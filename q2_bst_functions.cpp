#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
    Node *root;

    // (a) Recursive search
    Node *searchRecursive(Node *node, int key)
    {
        if (!node || node->data == key)
            return node;
        if (key < node->data)
            return searchRecursive(node->left, key);
        return searchRecursive(node->right, key);
    }

    // Helper function to insert nodes
    Node *insert(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    // Helper to find inorder successor
    Node *findMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Helper to find inorder predecessor
    Node *findMax(Node *node)
    {
        while (node && node->right)
            node = node->right;
        return node;
    }

public:
    BST() : root(nullptr) {}

    void insertValue(int val)
    {
        root = insert(root, val);
    }

    // (a) Search - Recursive
    bool searchRecursive(int key)
    {
        Node *result = searchRecursive(root, key);
        return result != nullptr;
    }

    // (a) Search - Non-Recursive
    bool searchNonRecursive(int key)
    {
        Node *current = root;
        while (current)
        {
            if (current->data == key)
                return true;
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    // (b) Maximum element
    int findMaximum()
    {
        if (!root)
            return -1; // Empty tree
        Node *current = root;
        while (current->right)
            current = current->right;
        return current->data;
    }

    // (c) Minimum element
    int findMinimum()
    {
        if (!root)
            return -1; // Empty tree
        Node *current = root;
        while (current->left)
            current = current->left;
        return current->data;
    }

    // (d) Inorder successor
    int findSuccessor(int key)
    {
        Node *keyNode = searchRecursive(root, key);
        if (!keyNode)
            return -1; // Key not found

        // Case 1: Node has right subtree
        if (keyNode->right)
        {
            return findMin(keyNode->right)->data;
        }

        // Case 2: No right subtree, find ancestor
        Node *successor = nullptr;
        Node *current = root;

        while (current)
        {
            if (key < current->data)
            {
                successor = current;
                current = current->left;
            }
            else if (key > current->data)
            {
                current = current->right;
            }
            else
            {
                break;
            }
        }

        return successor ? successor->data : -1;
    }

    // (e) Inorder predecessor
    int findPredecessor(int key)
    {
        Node *keyNode = searchRecursive(root, key);
        if (!keyNode)
            return -1; // Key not found

        // Case 1: Node has left subtree
        if (keyNode->left)
        {
            return findMax(keyNode->left)->data;
        }

        // Case 2: No left subtree, find ancestor
        Node *predecessor = nullptr;
        Node *current = root;

        while (current)
        {
            if (key > current->data)
            {
                predecessor = current;
                current = current->right;
            }
            else if (key < current->data)
            {
                current = current->left;
            }
            else
            {
                break;
            }
        }

        return predecessor ? predecessor->data : -1;
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void displayInorder()
    {
        cout << "BST Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST bst;

    // Create a sample BST: 50, 30, 70, 20, 40, 60, 80
    bst.insertValue(50);
    bst.insertValue(30);
    bst.insertValue(70);
    bst.insertValue(20);
    bst.insertValue(40);
    bst.insertValue(60);
    bst.insertValue(80);

    cout << "BST Functions Demo:\n";
    bst.displayInorder();

    // Testing search functions
    cout << "\nSearch 40 (Recursive): " << (bst.searchRecursive(40) ? "Found" : "Not Found") << endl;
    cout << "Search 40 (Non-Recursive): " << (bst.searchNonRecursive(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (bst.searchRecursive(90) ? "Found" : "Not Found") << endl;

    // Min and Max
    cout << "\nMinimum element: " << bst.findMinimum() << endl;
    cout << "Maximum element: " << bst.findMaximum() << endl;

    // Successor and Predecessor
    cout << "\nSuccessor of 30: " << bst.findSuccessor(30) << endl;
    cout << "Predecessor of 30: " << bst.findPredecessor(30) << endl;
    cout << "Successor of 70: " << bst.findSuccessor(70) << endl;
    cout << "Predecessor of 70: " << bst.findPredecessor(70) << endl;

    return 0;
}