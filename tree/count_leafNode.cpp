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

// count the number of leaf nodes in the tree
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right); 
}

int main() {
    cout << "Create a Binary Tree:\n";
    Node* root = createTree();

    cout << "\nTotal Number of Leaf Nodes: " << countLeafNodes(root) << endl;

    return 0;
}
