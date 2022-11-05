#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

int countNodes(BinaryTreeNode<int>* root) {
    // Agar root null to return 0
    if (root == NULL) return 0;

    // Otherwise pmi will give us count of left+right + 1 for root
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Inorder is used only for Binary Trees
void inorder(BinaryTreeNode<int>* root) {

    //Base Case
    if (root == NULL) return;

    //Inorder left phir root and finally right call krdia
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

// Print Binary Tree Level wise
void printTreeLevelWise(BinaryTreeNode<int>* root) {
    // Base Case
    if (root == NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    // Ab queue mein jbtk h tbtk ye chlega
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        //Binary tree mein unlike tree always make sure ki 2 calls krrhe h left and right to check null kuuki 2 hi child honge
        if (front->left != NULL) {
            cout << "L : " << front->left->data;
            pendingNodes.push(front->left);
        } else {
            cout << "L : -1 ";
        }
        if (front->right != NULL) {
            cout << "R : " << front->right->data;
            pendingNodes.push(front->right);
        } else {
            cout << "L : -1 ";
        }
        cout << endl;
    }
}

int main() {
    //1 2 -1 -1 3 -1 -1
    //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << endl;
    inorder(root);
    cout << endl;
    cout << countNodes(root);
    return 0;
}