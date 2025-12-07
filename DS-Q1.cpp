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
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = 0;
    }
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int x, int pos) {
        if (pos == 1) {
            insertAtBeginning(x);
            return;
        }
        Node* newNode = new Node(x);
        Node* temp = head;
        for (int i = 1; temp != 0 && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == 0) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeFromBeginning() {
        if (head == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromPosition(int pos) {
        if (head == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos == 1) {
            removeFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != 0 && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == 0 || temp->next == 0) {
            cout << "Position out of range!" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void removeBeginningAgain() {
        removeFromBeginning();
    }

    Node* search(int x) {
        Node* temp = head;
        while (temp != 0) {
            if (temp->data == x) {
                return temp;
            }
            temp = temp->next;
        }
        return 0;
    }

    void display() {
        Node* temp = head;
        if (temp == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "List: ";
        while (temp != 0) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
 
int main() {
    SinglyLinkedList list;
    int choice, x, pos;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at ith position\n";
        cout << "3. Remove from beginning\n";
        cout << "4. Remove from ith position\n";
        cout << "5. Remove from beginning (again)\n";
        cout << "6. Search element\n";
        cout << "7. Display list\n";
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
            cout << "Enter element and position: ";
            cin >> x >> pos;
            list.insertAtPosition(x, pos);
            break;
        case 3:
            list.removeFromBeginning();
            break;
        case 4:
            cout << "Enter position: ";
            cin >> pos;
            list.removeFromPosition(pos);
            break;
        case 5:
            list.removeBeginningAgain();
            break;
        case 6:
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
        case 7:
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

