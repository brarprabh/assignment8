#include <iostream>
#include <algorithm>
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

    Node *insert(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        // No duplicates allowed
        return node;
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int val)
    {
        if (!node)
            return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else
        {
            // Node to be deleted found
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(Node *node)
    {
        if (!node)
            return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node *node)
    {
        if (!node)
            return 0;
        if (!node->left)
            return 1 + minDepth(node->right);
        if (!node->right)
            return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }

public:
    BST() : root(nullptr) {}

    // (a) Insert element (no duplicates)
    void insertElement(int val)
    {
        root = insert(root, val);
        cout << "Inserted: " << val << endl;
    }

    // (b) Delete element
    void deleteElement(int val)
    {
        root = deleteNode(root, val);
        cout << "Deleted: " << val << endl;
    }

    // (c) Maximum depth
    int getMaxDepth()
    {
        return maxDepth(root);
    }

    // (d) Minimum depth
    int getMinDepth()
    {
        return minDepth(root);
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

    bool isEmpty()
    {
        return root == nullptr;
    }
};

int main()
{
    BST bst;

    cout << "BST Operations Demo:\n";

    // (a) Insert elements
    cout << "\nInserting elements:\n";
    bst.insertElement(50);
    bst.insertElement(30);
    bst.insertElement(70);
    bst.insertElement(20);
    bst.insertElement(40);
    bst.insertElement(60);
    bst.insertElement(80);
    bst.insertElement(30); // Duplicate - should be ignored

    bst.displayInorder();

    // (c) and (d) Depth calculations
    cout << "\nDepth calculations:\n";
    cout << "Maximum depth: " << bst.getMaxDepth() << endl;
    cout << "Minimum depth: " << bst.getMinDepth() << endl;

    // (b) Delete elements
    cout << "\nDeleting elements:\n";
    bst.deleteElement(20); // Leaf node
    bst.displayInorder();

    bst.deleteElement(30); // Node with two children
    bst.displayInorder();

    bst.deleteElement(50); // Root node
    bst.displayInorder();

    cout << "\nAfter deletions:\n";
    cout << "Maximum depth: " << bst.getMaxDepth() << endl;
    cout << "Minimum depth: " << bst.getMinDepth() << endl;

    return 0;
}