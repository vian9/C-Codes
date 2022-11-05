#include<bits/stdc++.h>
#include"treenode.h"
using namespace std;

void printTree(TreeNode<int>* root) {
    if (root == NULL)
    {
        return;
    }

    // Root print kia
    cout << root->data << endl;
    // Root k children print kia
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << endl;
    }

    // Ab saare children pr recursion call krdia
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }

}

void printTreeLevelWise(TreeNode<int>* root) {
    // Agar root is NULL
    if (root == NULL)
    {
        return;
    }

    cout << "Root is " << root->data << endl;
    // Queue lia and usko root mein push krdia for FIFO level wise print
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        // Front of queue nikala and pop krdia
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        // Front k saare children on 1 level print ho jayega
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " , ";
            // Saare children push krdia queue mein
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter Root Data :" << endl;
    cin >> rootData;
    // Root lelia and uska children puch lia and ab usse children ko input le lenge
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter the number of children" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // Ab usse child k liye recursive call krdia jo input le lega
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

TreeNode<int>* takeInputLevelWise() {
    //Rootdata lelia and uska node bana lia
    int rootData;
    cout << "Enter Root Data :" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    // Queue mein jaise jaise aayega we will push FIFO se level wise hoga
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front->data << endl;
        // EK level wale here front ko lia and uske child input le lenge
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter" << i << "th Child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            // Child bhi push hogya queue mein jo ki baad mein aayega to ask for children
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    // 1 3 2 3 4 2 5 6 0 0 0 0
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* child1 = new TreeNode<int>(1);
    TreeNode<int>* child2 = new TreeNode<int>(2);
    TreeNode<int>* child3 = new TreeNode<int>(3);
    TreeNode<int>* child4 = new TreeNode<int>(4);
    TreeNode<int>* child5 = new TreeNode<int>(5);
    TreeNode<int>* child6 = new TreeNode<int>(6);
    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(child3);
    child2->children.push_back(child4);
    child3->children.push_back(child5);
    child4->children.push_back(child6);
    printTree(root);

    cout << endl;
    // printTree(takeInput());
    printTreeLevelWise(takeInputLevelWise());
    return 0;
}