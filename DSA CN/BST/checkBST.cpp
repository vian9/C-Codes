#include<bits/stdc++.h>
#include "binarytree.h"
using namespace std;

// Construct a BST from Sorted Array
BinaryTreeNode<int>* makeBST(vector<int>& nums, int low, int high) {
    // Base condition for jb bhi low high laga rhe ho toh
    if (low > high) {
        return NULL;
    }
    // Mid is root
    int mid = low + (high - low) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(nums[mid]);

    // Yeh PMI se pura tree bst bnakr lakr dega
    BinaryTreeNode<int>* leftBST = makeBST(nums, low, mid - 1);
    BinaryTreeNode<int>* rightBST = makeBST(nums, mid + 1, high);
    // Just connect it
    root->left = leftBST;
    root->right = rightBST;

    return root;
}

// Root to Node Path....can't be done without dynamic vector bcoz recursion mein same vector bhejna h
vector<int>* rootPath(BinaryTreeNode<int>* root, int data) {
    // Base Case
    if (root == NULL)
        return NULL;

    // Root k sth match toh return
    if (root->data == data) {
        vector<int>* nums = new vector<int>();
        nums->push_back(root->data);
        return nums;
    }

    // Left ko call
    vector<int>* leftnums = rootPath(root->left, data);
    //Agar left mein mila toh root ko add krke return
    if (leftnums != NULL)
    {
        leftnums->push_back(root->data);
        return leftnums;
    }

    // Right mein call 
    vector<int>* rightnums = rootPath(root->right, data);
    if (rightnums != NULL)
    {
        rightnums->push_back(root->data);
        return rightnums;
    }
    return NULL;
}

//CLass for isBST2
class isBstReturn {
public:
    bool isBST;
    int minimum;
    int maximum;
};

// Like Binary tree diamter both min and max return krenge ek sth and check
isBstReturn isBST2(BinaryTreeNode<int>* root) {
    // Base Case
    if (root == NULL) {
        isBstReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    //Left and Right se saara data lelia
    isBstReturn isLeftOk = isBST2(root->left);
    isBstReturn isRightOk = isBST2(root->right);

    // Ab min and max overall nikaldia jo aage andar kaam aayega
    int minimum = min(root->data, min(isLeftOk.minimum, isRightOk.minimum));
    int maximum = max(root->data, max(isLeftOk.maximum, isRightOk.maximum));

    //Check for BST
    bool isBSTFinal = (root->data > isLeftOk.maximum) && (root->data <= isRightOk.minimum) && isLeftOk.isBST && isRightOk.isBST;

    isBstReturn final;
    final.isBST = isBSTFinal;
    final.minimum = minimum;
    final.maximum = maximum;
    return final;
}

// Check BST with constraints
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    // Base Case
    if (root == NULL)
        return true;

    // check constraints for root
    if (root->data < min || root->data > max)
        return false;

    // Ab left and right check krlo ki sahi kaam krrha h na
    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);

    return isLeftOk && isRightOk;
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
    // BinaryTreeNode<int>* root = takeInputLevelWise();
    vector<int> nums = { 1,2,3,4,5,6,7 };
    BinaryTreeNode<int>* root2 = makeBST(nums, 0, 6);
    printTreeLevelWise(root2);
    vector<int>* nums1 = rootPath(root2, 7);
    vector<int> ::iterator it = nums1->begin();
    while (it != nums1->end())
    {
        cout << *it << endl;
        it++;
    }

    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    return 0;
}