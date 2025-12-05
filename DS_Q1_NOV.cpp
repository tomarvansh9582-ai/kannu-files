#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Adder {
    stack<int> s1, s2, res;
public:
    void getInput() {
        string n1, n2;
        cout << "Enter first number: ";
        cin >> n1;
        cout << "Enter second number: ";
        cin >> n2;
		for (int i = 0; i < n1.length(); i++)
            s1.push(n1[i] - '0');
		for (int i = 0; i < n2.length(); i++)
            s2.push(n2[i] - '0');
    }
	void add() {
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int a = 0, b = 0;
            if (!s1.empty()) { a = s1.top(); s1.pop(); }
            if (!s2.empty()) { b = s2.top(); s2.pop(); }
			int sum = a + b + carry;
            res.push(sum % 10);
            carry = sum / 10;
        }
    }
	void showResult() {
        cout << "Sum = ";
        while (!res.empty()) {
            cout << res.top();
            res.pop();
        }
        cout << endl;
    }
};
int main() {
    Adder obj;
    obj.getInput();
    obj.add();
    obj.showResult();
    return 0;
}
