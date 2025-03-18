#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//  insert a node in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// search for a value in BST
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left; 
    return root;
}

// Delete function
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root; 

    if (key < root->data) root->left = deleteNode(root->left, key); 
    else if (key > root->data) root->right = deleteNode(root->right, key); 
    
    else { // Found node to delete
        if (root->left == nullptr) { Node* temp = root->right; delete root; return temp; } // One child (right)
        else if (root->right == nullptr) { Node* temp = root->left; delete root; return temp; } // One child (left)

        Node* temp = findMin(root->right); // Two children: Get inorder successor
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Search 40: " << (search(root, 40) ? "Found\n" : "Not Found\n");
    
    root = deleteNode(root, 50); // Deleting node 50

    cout << "Search 50: " << (search(root, 50) ? "Found\n" : "Not Found\n");


    return 0;
}