#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

// Take input
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter the root: " << endl;
    cin >> rootData;

    //Agar -1 mila toh null consider krenge
    if (rootData == -1)
    {
        return NULL;
    }

    // Ab recursion se left and right child ko call krdiye and phir input lene k baad connect krdia
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
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

//Print Tree
void printTree(BinaryTreeNode<int>* root) {
    //Base Case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : " << endl;
    // Agar left and right exists to print
    if (root->left != NULL)
    {
        cout << "L " << root->left->data;
    }
    cout << endl;
    if (root->right != NULL)
    {
        cout << "R " << root->right->data;
    }

    cout << endl;
    // Binary Tree mein dono left and right mein call krna hoga
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // 1 2 -1 -1 3 -1 -1
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(14);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(12);
    root->left = node1;
    root->right = node2;
    BinaryTreeNode<int>* root1 = takeInput();
    printTreeLevelWise(root1);
    return 0;
}