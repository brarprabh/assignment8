#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    Node *root;

    void preorderRec(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void inorderRec(Node *node)
    {
        if (!node)
            return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void postorderRec(Node *node)
    {
        if (!node)
            return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void createSampleTree()
    {
        // Creating a sample tree:
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
    }

    void preorderTraversal()
    {
        cout << "Pre-order traversal: ";
        preorderRec(root);
        cout << endl;
    }

    void inorderTraversal()
    {
        cout << "In-order traversal: ";
        inorderRec(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        cout << "Post-order traversal: ";
        postorderRec(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    tree.createSampleTree();

    cout << "Binary Tree Traversals:\n";
    tree.preorderTraversal();  // Output: 1 2 4 5 3
    tree.inorderTraversal();   // Output: 4 2 5 1 3
    tree.postorderTraversal(); // Output: 4 5 2 3 1

    return 0;
}