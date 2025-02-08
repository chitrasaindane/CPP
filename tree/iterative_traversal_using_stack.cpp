#include <iostream>
#include <stack>
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

// Iterative Inorder Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

// Iterative Preorder Traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

// Iterative Postorder Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    cout << "Create a Binary Tree:\n";
    Node* root = createTree();

    cout << "\nInorder Traversal (Iterative): ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal (Iterative): ";
    preorderTraversal(root);

    cout << "\nPostorder Traversal (Iterative): ";
    postorderTraversal(root);

    cout << endl;
    return 0;
}
