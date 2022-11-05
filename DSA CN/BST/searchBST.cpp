#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

// Search in BST
BinaryTreeNode<int>* searchBST(BinaryTreeNode<int>* root, int data2) {
    if (root == NULL)
    {
        return NULL;
    }
    int rootData = root->data;

    if (data2 == rootData)
        return root;
    else if (data2 > rootData)
        // Recursive Binary Search mein return jrur kro harr case mein....iterative mein bas value badalte h 
        return searchBST(root->right, data2);
    else
        return searchBST(root->left, data2);

    return NULL;
}

// Elements in Range
void searchRangeBST(BinaryTreeNode<int>* root, int low, int high) {
    if (root == NULL)
    {
        return;
    }
    int rootData = root->data;

    // Kuuki 3 range mein ho skta h toh teeno k liye alag if lgega na ki if...else
    if (root->data > low) {
        searchRangeBST(root->left, low, high);
    }
    if (root->data >= low && root->data <= high) {
        cout << root->data << endl;
    }
    if (root->data < high)
    {
        searchRangeBST(root->right, low, high);
    }
}

// Take Input level wise
BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter the root: " << endl;
    cin >> rootData;

    //Agar -1 mila toh null consider krenge
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        //Left Child entry
        cout << "Enter the left child of: " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;

        // -1 nhi hua to enter
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        // Right Child Entry
        cout << "Enter the right child of: " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;

        // -1 nhi hua to enter
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    BinaryTreeNode<int>* root2 = searchBST(root, 5);
    cout << root2->data << endl;
    searchRangeBST(root, 2, 6);
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    return 0;
}