#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = 0;
    }
};

// BST class
class BST {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* node, int x) {
        if (node == 0) return new Node(x);
        if (x < node->data)
            node->left = insert(node->left, x);
        else if (x > node->data)
            node->right = insert(node->right, x);
        return node;
    }

    // Helper function for searching
    Node* search(Node* node, int x) {
        if (node == 0 || node->data == x) return node;
        if (x < node->data) return search(node->left, x);
        return search(node->right, x);
    }

    // Helper function for finding minimum value node
    Node* findMin(Node* node) {
        while (node->left != 0) node = node->left;
        return node;
    }

    // Helper function for deletion
    Node* deleteNode(Node* node, int x) {
        if (node == 0) return node;
        if (x < node->data)
            node->left = deleteNode(node->left, x);
        else if (x > node->data)
            node->right = deleteNode(node->right, x);
        else {
            // Node found
            if (node->left == 0) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == 0) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Traversals
    void inorder(Node* node) {
        if (node != 0) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != 0) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != 0) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST() {
        root = 0;
    }

    void insert(int x) {
        root = insert(root, x);
    }

    void deleteNode(int x) {
        root = deleteNode(root, x);
    }

    void search(int x) {
        Node* result = search(root, x);
        if (result != 0)
            cout << "Element " << x << " found at address: " << result << endl;
        else
            cout << "Element " << x << " not found!" << endl;
    }

    void displayTraversals() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;

        cout << "Preorder: ";
        preorder(root);
        cout << endl;

        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

// Menu-driven program
int main() {
    BST tree;
    int choice, x;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Search element\n";
        cout << "4. Display traversals\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            tree.insert(x);
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> x;
            tree.deleteNode(x);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> x;
            tree.search(x);
            break;
        case 4:
            tree.displayTraversals();
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

