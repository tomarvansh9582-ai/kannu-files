#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = 0;
        height = 1;
    }
};

// AVL Tree class
class AVL {
private:
    Node* root;

    // Utility: get height
    int getHeight(Node* node) {
        if (node == 0) return 0;
        return node->height;
    }

    // Utility: get balance factor
    int getBalance(Node* node) {
        if (node == 0) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Insert helper
    Node* insert(Node* node, int key) {
        if (node == 0) return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; // duplicate keys not allowed

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get balance factor
        int balance = getBalance(node);

        // Balance cases
        // Left Left
        if (balance > 1 && key < node->left->data)
            return rotateRight(node);

        // Right Right
        if (balance < -1 && key > node->right->data)
            return rotateLeft(node);

        // Left Right
        if (balance > 1 && key > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left
        if (balance < -1 && key < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Search helper
    Node* search(Node* node, int key) {
        if (node == 0 || node->data == key) return node;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

    // Inorder traversal (for debugging)
    void inorder(Node* node) {
        if (node != 0) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVL() {
        root = 0;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void search(int key) {
        Node* result = search(root, key);
        if (result != 0)
            cout << "Element " << key << " found at address: " << result << endl;
        else
            cout << "Element " << key << " not found!" << endl;
    }

    void displayInorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }
};

// Menu-driven program
int main() {
    AVL tree;
    int choice, x;

    do {
        cout << "\n--- AVL Tree Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Search element\n";
        cout << "3. Display inorder traversal\n";
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
            cout << "Enter element to search: ";
            cin >> x;
            tree.search(x);
            break;
        case 3:
            tree.displayInorder();
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

