#include <bits/stdc++.h>
using namespace std;

// Pre-order Traversal (Root, Left, Right)
void preorderTraversal(vector<int>& tree, int index, int size) {
    if (index >= size || tree[index] == -1) return;  // -1 represents null in this example

    cout << tree[index] << " ";                      // Visit root
    preorderTraversal(tree, 2 * index + 1, size);    // Traverse left subtree
    preorderTraversal(tree, 2 * index + 2, size);    // Traverse right subtree
}

// In-order Traversal (Left, Root, Right)
void inorderTraversal(vector<int>& tree, int index, int size) {
    if (index >= size || tree[index] == -1) return;

    inorderTraversal(tree, 2 * index + 1, size);     // Traverse left subtree
    cout << tree[index] << " ";                      // Visit root
    inorderTraversal(tree, 2 * index + 2, size);     // Traverse right subtree
}

// Post-order Traversal (Left, Right, Root)
void postorderTraversal(vector<int>& tree, int index, int size) {
    if (index >= size || tree[index] == -1) return;

    postorderTraversal(tree, 2 * index + 1, size);   // Traverse left subtree
    postorderTraversal(tree, 2 * index + 2, size);   // Traverse right subtree
    cout << tree[index] << " ";                      // Visit root
}

int main() {
    // Input array representing the tree
    // Example tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    // Array representation (using -1 for null nodes):
    cout<<"Enter the node number: ";
    int x;
    cin>>x;

    vector<int> tree;
    for (int i = 0; i < x; i++)
    {
        int a;
        cin>>a;
        tree.push_back(a);
    }
    
    

    int size = tree.size();

    cout << "Pre-order traversal: ";
    preorderTraversal(tree, 0, size);
    cout << endl;

    cout << "In-order traversal: ";
    inorderTraversal(tree, 0, size);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(tree, 0, size);
    cout << endl;

    return 0;
}
