#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = 0;
        next = 0;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = 0;
        tail = 0;
    }

    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        if (head == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (tail == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeFromBeginning() {
        if (head == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = 0;
        } else {
            head = head->next;
            head->prev = 0;
        }
        delete temp;
    }

    void removeFromEnd() {
        if (tail == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = 0;
        } else {
            tail = tail->prev;
            tail->next = 0;
        }
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        if (temp == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "List (forward): ";
        while (temp != 0) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        if (temp == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "List (backward): ";
        while (temp != 0) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, x;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Remove from beginning\n";
        cout << "4. Remove from end\n";
        cout << "5. Display forward\n";
        cout << "6. Display backward\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            list.insertAtBeginning(x);
            break;
        case 2:
            cout << "Enter element: ";
            cin >> x;
            list.insertAtEnd(x);
            break;
        case 3:
            list.removeFromBeginning();
            break;
        case 4:
            list.removeFromEnd();
            break;
        case 5:
            list.displayForward();
            break;
        case 6:
            list.displayBackward();
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

