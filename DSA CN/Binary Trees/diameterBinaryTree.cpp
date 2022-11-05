#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

//Height of Binary tree function
int heighBinary(BinaryTreeNode<int>* root) {
    //Base Case
    if (root == NULL) return 0;

    // root + jo bhi max hoga
    return 1 + max(heighBinary(root->left), heighBinary(root->right));
}

//Diameter of tree O(nlogn) or O(nh) where n is no of nodes and h is height
int diameterBinary(BinaryTreeNode<int>* root) {
    //Base Case
    if (root == NULL)
        return 0;

    // Diameter will be among either leftHt+rightHt  or LeftDiamter or RightDiameter
    int opt1 = heighBinary(root->left) + heighBinary(root->right) + 1;
    int opt2 = diameterBinary(root->left);
    int opt3 = diameterBinary(root->right);
    return max(opt1, max(opt2, opt3));
}

//Optimised Solution for Diamter and height - O(n)
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    //Pair k 1st mein height and second mein diameter rkhenge
    //Base Case
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> p;

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    // Ab height k liye root + max of left or right height
    int height = 1 + max(lh, rh);
    // Diameter will be among either leftHt+rightHt  or LeftDiamter or RightDiameter
    int diameter = max(1 + lh + rh, max(ld, rd));
    p.first = height;
    p.second = diameter;
    return p;
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
    cout << heighBinary(root) << endl;
    cout << diameterBinary(root);
    cout << endl;
    pair<int, int> ans = heightDiameter(root);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}