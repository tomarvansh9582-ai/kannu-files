#include <iostream>
using namespace std;

class InsertionSort {
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

    // Function to perform insertion sort
    void sortArray() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            // Move elements greater than key one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Function to display the array
    void displayArray() {
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    InsertionSort is;
    is.inputArray();

    cout << "Sorting array using Insertion Sort...\n";
    is.sortArray();

    is.displayArray();

    return 0;
}

