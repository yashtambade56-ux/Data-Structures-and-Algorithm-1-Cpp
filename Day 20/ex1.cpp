#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    bool isLeaf;
    vector<int> keys;
    vector<Node*> child;
    Node* next;

    Node(bool leaf = false) {
        isLeaf = leaf;
        next = NULL;
    }
};

class BPlusTree {
    Node* root;
    int MAX_KEYS;

public:
    BPlusTree(int maxKeys) {
        root = NULL;
        MAX_KEYS = maxKeys;
    }

    void insert(int key) {
        if (root == NULL) {
            root = new Node(true);
            root->keys.push_back(key);
            return;
        }

        vector<Node*> path;
        Node* cursor = root;

        // Traverse to leaf
        while (!cursor->isLeaf) {
            path.push_back(cursor);
            int i = 0;
            while (i < cursor->keys.size() && key >= cursor->keys[i])
                i++;
            cursor = cursor->child[i];
        }

        // Insert in leaf
        cursor->keys.push_back(key);
        sort(cursor->keys.begin(), cursor->keys.end());

        // Split if overflow
        if (cursor->keys.size() > MAX_KEYS) {
            splitLeaf(cursor, path);
        }
    }

    void splitLeaf(Node* leaf, vector<Node*>& path) {
        Node* newLeaf = new Node(true);
        int mid = (leaf->keys.size() + 1) / 2;

        // move half keys
        newLeaf->keys.assign(leaf->keys.begin() + mid, leaf->keys.end());
        leaf->keys.resize(mid);

        // link leaves
        newLeaf->next = leaf->next;
        leaf->next = newLeaf;

        int promoteKey = newLeaf->keys[0];

        // if root
        if (path.empty()) {
            Node* newRoot = new Node(false);
            newRoot->keys.push_back(promoteKey);
            newRoot->child.push_back(leaf);
            newRoot->child.push_back(newLeaf);
            root = newRoot;
            return;
        }

        insertInternal(path, promoteKey, leaf, newLeaf);
    }

    void insertInternal(vector<Node*>& path, int key, Node* left, Node* right) {
        Node* parent = path.back();
        path.pop_back();

        // find position
        int idx = 0;
        while (idx < parent->keys.size() && key >= parent->keys[idx])
            idx++;

        parent->keys.insert(parent->keys.begin() + idx, key);

        parent->child.insert(parent->child.begin() + idx + 1, right);

        if (parent->keys.size() > MAX_KEYS) {
            splitInternal(parent, path);
        }
    }

    void splitInternal(Node* node, vector<Node*>& path) {
        Node* newNode = new Node(false);

        int mid = node->keys.size() / 2;
        int promoteKey = node->keys[mid];

        // right keys
        newNode->keys.assign(node->keys.begin() + mid + 1, node->keys.end());
        node->keys.resize(mid);

        // right children
        newNode->child.assign(node->child.begin() + mid + 1, node->child.end());
        node->child.resize(mid + 1);

        if (path.empty()) {
            Node* newRoot = new Node(false);
            newRoot->keys.push_back(promoteKey);
            newRoot->child.push_back(node);
            newRoot->child.push_back(newNode);
            root = newRoot;
            return;
        }

        insertInternal(path, promoteKey, node, newNode);
    }

    void display() {
        Node* cursor = root;

        while (cursor && !cursor->isLeaf)
            cursor = cursor->child[0];

        while (cursor) {
            cout << "[ ";
            for (int k : cursor->keys)
                cout << k << " ";
            cout << "] -> ";
            cursor = cursor->next;
        }
        cout << "NULL\n";
    }

    bool search(int key) {
        Node* cursor = root;

        while (cursor && !cursor->isLeaf) {
            int i = 0;
            while (i < cursor->keys.size() && key >= cursor->keys[i])
                i++;
            cursor = cursor->child[i];
        }

        if (!cursor) return false;

        return find(cursor->keys.begin(), cursor->keys.end(), key) != cursor->keys.end();
    }
};

int main() {
    BPlusTree tree(2);

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);

    cout << "B+ Tree Leaf Nodes:\n";
    tree.display();

    cout << "\nSearch 12: ";
    cout << (tree.search(12) ? "Found" : "Not Found");

    return 0;
}