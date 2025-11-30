#include <iostream>
#include <climits>
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

    // Helper function to check if tree is BST
    bool isBSTUtil(Node *node, int minVal, int maxVal)
    {
        // Empty tree is BST
        if (!node)
            return true;

        // Check current node's value
        if (node->data <= minVal || node->data >= maxVal)
            return false;

        // Recursively check left and right subtrees
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }

    // Alternative method using inorder traversal
    void inorderTraversal(Node *node, int &prev, bool &isBST)
    {
        if (!node || !isBST)
            return;

        inorderTraversal(node->left, prev, isBST);

        if (prev >= node->data)
        {
            isBST = false;
            return;
        }
        prev = node->data;

        inorderTraversal(node->right, prev, isBST);
    }

public:
    BinaryTree() : root(nullptr) {}

    // Create a sample BST
    void createValidBST()
    {
        root = new Node(20);
        root->left = new Node(10);
        root->right = new Node(30);
        root->left->left = new Node(5);
        root->left->right = new Node(15);
        root->right->left = new Node(25);
        root->right->right = new Node(35);
    }

    // Create an invalid BST (violates BST property)
    void createInvalidBST()
    {
        root = new Node(20);
        root->left = new Node(10);
        root->right = new Node(30);
        root->left->left = new Node(5);
        root->left->right = new Node(25); // This violates BST property
        root->right->left = new Node(15); // This violates BST property
        root->right->right = new Node(35);
    }

    // Method 1: Using min-max bounds
    bool isBSTMethod1()
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }

    // Method 2: Using inorder traversal
    bool isBSTMethod2()
    {
        int prev = INT_MIN;
        bool isBST = true;
        inorderTraversal(root, prev, isBST);
        return isBST;
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void displayTree()
    {
        cout << "Tree (Inorder): ";
        inorder(root);
        cout << endl;
    }

    void clearTree()
    {
        // Simple clear for demo purposes
        root = nullptr;
    }
};

int main()
{
    BinaryTree tree;

    cout << "Check if Binary Tree is BST Demo:\n";

    // Test 1: Valid BST
    cout << "\nTest 1: Valid BST\n";
    tree.createValidBST();
    tree.displayTree();
    cout << "Is BST (Method 1 - Min/Max): " << (tree.isBSTMethod1() ? "Yes" : "No") << endl;
    cout << "Is BST (Method 2 - Inorder): " << (tree.isBSTMethod2() ? "Yes" : "No") << endl;

    // Test 2: Invalid BST
    cout << "\nTest 2: Invalid BST\n";
    tree.clearTree();
    tree.createInvalidBST();
    tree.displayTree();
    cout << "Is BST (Method 1 - Min/Max): " << (tree.isBSTMethod1() ? "Yes" : "No") << endl;
    cout << "Is BST (Method 2 - Inorder): " << (tree.isBSTMethod2() ? "Yes" : "No") << endl;

    // Test 3: Single node tree
    cout << "\nTest 3: Single Node Tree\n";
    tree.clearTree();
    tree.root = new Node(42);
    tree.displayTree();
    cout << "Is BST (Method 1 - Min/Max): " << (tree.isBSTMethod1() ? "Yes" : "No") << endl;
    cout << "Is BST (Method 2 - Inorder): " << (tree.isBSTMethod2() ? "Yes" : "No") << endl;

    return 0;
}