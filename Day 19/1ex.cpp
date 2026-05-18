#include <iostream>
using namespace std;

// B-Tree Node
class BTreeNode {
    int *keys;          // Array of keys
    int t;              // Minimum degree
    BTreeNode **C;      // Child pointers
    int n;              // Current number of keys
    bool leaf;          // True if leaf node

public:
    BTreeNode(int _t, bool _leaf);

    void traverse();
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);

    friend class BTree;
};

// Constructor
BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;

    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];

    n = 0;
}

// Traverse all nodes
void BTreeNode::traverse() {
    int i;

    for (i = 0; i < n; i++) {

        // Traverse child before key
        if (!leaf)
            C[i]->traverse();

        cout << keys[i] << " ";
    }

    // Traverse last child
    if (!leaf)
        C[i]->traverse();
}

// Insert into non-full node
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    // If leaf node
    if (leaf) {

        // Move keys greater than k
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n++;
    }
    else {

        // Find child to insert
        while (i >= 0 && keys[i] > k)
            i--;

        // If child is full
        if (C[i + 1]->n == 2 * t - 1) {

            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }

        C[i + 1]->insertNonFull(k);
    }
}

// Split child
void BTreeNode::splitChild(int i, BTreeNode *y) {

    // Create new node
    BTreeNode *z = new BTreeNode(y->t, y->leaf);

    z->n = t - 1;

    // Copy last keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy child pointers
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // Reduce number of keys in y
    y->n = t - 1;

    // Create space for new child
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    // Move keys in current node
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // Middle key moves up
    keys[i] = y->keys[t - 1];

    // Increase key count
    n++;
}

// B-Tree Class
class BTree {
    BTreeNode *root;
    int t;

public:
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    void insert(int k);
};

// Insert function
void BTree::insert(int k) {

    // If tree empty
    if (root == NULL) {

        root = new BTreeNode(t, true);

        root->keys[0] = k;
        root->n = 1;
    }
    else {

        // If root full
        if (root->n == 2 * t - 1) {

            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            // Split old root
            s->splitChild(0, root);

            int i = 0;

            if (s->keys[0] < k)
                i++;

            s->C[i]->insertNonFull(k);

            // Change root
            root = s;
        }
        else {
            root->insertNonFull(k);
        }
    }
}

// Main Function
int main() {

    BTree t(3);

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of B-Tree:\n";

    t.traverse();

    return 0;
}