#include<bits/stdc++.h>
#include"treenode.h"
using namespace std;

// Count Number of Nodes
int countNodes(TreeNode<int>* root) {
    // 1 is for root
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        // Ab ans mein recursive call krdia for child....PMI se wo lakr hume de dega
        ans += countNodes(root->children[i]);
    }
    return ans;
}

// Calculate the height 
int treeHeight(TreeNode<int>* root) {
    // maximum height 0 lelia
    int maxi = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        // Ab harr child ko PMI se boldia ki height lekr aao....sochna mt kaise layega
        int heightLocal = treeHeight(root->children[i]);
        // max height jo hoga we will update
        maxi = max(maxi, heightLocal);
    }
    // Max + 1 for root is the height....base case yhi aa jata h for root
    return 1 + maxi;
}

// Depth of Node at Level k
void printAtLevelK(TreeNode<int>* root, int k) {
    //Base Case....agar k 0 ho toh root is ans....ab recursive call pr jb bhi hit krega wo print ho jayega
    if (k == 0) {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        // Ab child pr recursive call kr denge for level k-1
        printAtLevelK(root->children[i], k - 1);
    }

}

// To count Leaf nodes
int countLeafNodes(TreeNode<int>* root) {
    int count = 0;
    // Agar root null hai to zero
    if (root == NULL) return 0;
    // Agar root k child nhi to leaf node h to return 1 for it
    if (root->children.size() == 0) return 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += (countLeafNodes(root->children[i]));
    }
    return count;
}

// Preorder Print
void preOrderTree(TreeNode<int>* root) {
    // Edge Case
    if (root == NULL) return;
    cout << root->data << " : ";
    // Ab children ko bol denge khud print ho jao
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderTree(root->children[i]);
    }
}

// PostOrder Tree
void postOrderTree(TreeNode<int>* root) {
    if (root == NULL) return;
    // Child at bottom phle print hoga phir root
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTree(root->children[i]);
    }
    cout << root->data << " : ";
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
    // 1 2 2 4 1 3 1 5 0 1 6 0
    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << endl;
    cout << countLeafNodes(root);
    cout << endl;
    preOrderTree(root);
    cout << endl;
    postOrderTree(root);
    cout << endl;
    printAtLevelK(root, 2);
    cout << endl;
    cout << treeHeight(root);
    cout << endl;
    cout << countNodes(root);
    cout << endl;
    return 0;
}