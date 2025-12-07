#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = 0;
    }
};

class CircularLinkedList {
private:
    Node* tail;  

public:
    CircularLinkedList() {
        tail = 0;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        if (tail == 0) {
            tail = newNode;
            tail->next = tail; 
        } else {
            newNode->next = tail->next; 
            tail->next = newNode;
            tail = newNode; 
        }
    }

    void remove(int x) {
        if (tail == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* curr = tail->next; 
        Node* prev = tail;

        do {
            if (curr->data == x) {
                if (curr == tail && curr == tail->next) {
                    
                    delete curr;
                    tail = 0;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) {
                        tail = prev; 
                    }
                    delete curr;
                }
                cout << "Element " << x << " removed." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        cout << "Element not found!" << endl;
    }

    Node* search(int x) {
        if (tail == 0) return 0;

        Node* curr = tail->next;
        do {
            if (curr->data == x) return curr;
            curr = curr->next;
        } while (curr != tail->next);

        return 0;
    }

    void display() {
        if (tail == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* curr = tail->next;
        cout << "Circular List: ";
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, x;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Remove element\n";
        cout << "3. Search element\n";
        cout << "4. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            list.insert(x);
            break;
        case 2:
            cout << "Enter element to remove: ";
            cin >> x;
            list.remove(x);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> x;
            {
                Node* result = list.search(x);
                if (result != 0)
                    cout << "Element found at address: " << result << endl;
                else
                    cout << "Element not found!" << endl;
            }
            break;
        case 4:
            list.display();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

