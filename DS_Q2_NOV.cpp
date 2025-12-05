#include <iostream>
using namespace std;

int findMax(int A[], int n) {
    // Base case: only one element
    if (n == 1)
        return A[0];
    
    // Recursive case: find max of remaining elements
    int maxRest = findMax(A, n - 1);
    
    // Compare last element with max of rest
    return (A[n - 1] > maxRest) ? A[n - 1] : maxRest;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[100]; // simple static array
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Maximum element: " << findMax(A, n) << endl;
    return 0;
}
