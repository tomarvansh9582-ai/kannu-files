#include <iostream>
using namespace std;

class LinearSearch {
private:
    int arr[100];   // array to store elements
    int n;          // number of elements

public:
    // Function to take input from user
    void inputArray() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Function to perform linear search
    int searchElement(int key) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                return i; // return index if found
            }
        }
        return -1; // return -1 if not found
    }
};

int main() {
    LinearSearch ls;
    ls.inputArray();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = ls.searchElement(key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

