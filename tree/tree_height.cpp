#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// create a binary tree manually
Node* createTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if (data == -1) return NULL;

    Node* newNode = new Node(data);

    cout << "Enter left child of " << data << endl;
    newNode->left = createTree();

    cout << "Enter right child of " << data << endl;
    newNode->right = createTree();

    return newNode;
}

// find the height of a tree (Recursive)
int findHeight(Node* root) {
    if (root == NULL) return -1;  

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    cout << "Create a Binary Tree:\n";
    Node* root = createTree();

    cout << "\nHeight of the Tree: " << findHeight(root) << endl;

    return 0;
}
