#include <iostream>
using namespace std;

class BinarySearch {
private:
    int arr[100];   // array to store elements
    int n;          // number of elements

public:
    // Function to take input from user
    void inputArray() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter " << n << " elements in sorted order:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Function to perform binary search
    int searchElement(int key) {
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == key) {
                return mid; // element found
            }
            else if (arr[mid] < key) {
                low = mid + 1; // search right half
            }
            else {
                high = mid - 1; // search left half
            }
        }
        return -1; // element not found
    }
};

int main() {
    BinarySearch bs;
    bs.inputArray();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = bs.searchElement(key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

