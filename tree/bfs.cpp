#include <iostream>
#include <queue>
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

// create a binary tree 
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

// Level Order Traversal using a Queue
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front(); 
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);  
        if (current->right) q.push(current->right); 
    }
}

int main() {
    cout << "Create a Binary Tree:\n";
    Node* root = createTree();

    cout << "\nLevel Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
