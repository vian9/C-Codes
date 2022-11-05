#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../Pre/Functions.c"
#include "../Pre/Struct.c"

int nodesInAvl = 0;

AVL_Node* newAVLNode(Customer cust) {
    nodesInAvl++;
    AVL_Node* new_node = (AVL_Node*) malloc(sizeof(AVL_Node));
    if(new_node == NULL){
        printf("\n\t\t **MEMORY EXHAUSTED can't perform further operations!**\n\n");
        return NULL;
    }
    new_node->cust = cust;
    new_node->left = new_node->right = NULL;
    new_node->heightOfAvl = 1;
    return new_node;
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int heightOfAvl(AVL_Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->heightOfAvl;
}

int getBalanceFactor(AVL_Node* root) {
    if (root == NULL) {
        return 0;
    }
    return heightOfAvl(root->left) - heightOfAvl(root->right);
}

AVL_Node* leftRotate(AVL_Node* root) {
    AVL_Node* newMid = root->right;
    AVL_Node* temp = newMid->left;

    // rotation
    newMid->left = root;
    root->right = temp;

    // updating heightOfAvl
    root->heightOfAvl = max(heightOfAvl(root->left), heightOfAvl(root->right)) + 1;
    newMid->heightOfAvl = max(heightOfAvl(newMid->left), heightOfAvl(newMid->right)) + 1;

    // return new root after rotation
    return newMid;
}

AVL_Node* rightRotate(AVL_Node* root) {
    AVL_Node* newMid = root->left;
    AVL_Node* temp = newMid->right;

    // rotation
    newMid->right = root;
    root->left = temp;

    // updating heightOfAvl
    root->heightOfAvl = max(heightOfAvl(root->left), heightOfAvl(root->right)) + 1;
    newMid->heightOfAvl = max(heightOfAvl(newMid->left), heightOfAvl(newMid->right)) + 1;

    // return new root after rotation
    return newMid;
}

AVL_Node* insertAVL(AVL_Node* root, Customer cust) {

    // 1. Normal BST insertAVL
    if (root == NULL) {
        // printf("\n=========inserted===========\n");
        root = newAVLNode(cust);
    } else if (stringCompare(cust.mobNo, root->cust.mobNo) < 0) {
        root->left = insertAVL(root->left, cust);
    } else if (stringCompare( cust.mobNo,root->cust.mobNo) > 0) {
        root->right = insertAVL(root->right, cust);
    } else {
        return root;
    }

    // 2. Updata heightOfAvl of ancestor nodes
    root->heightOfAvl = 1 + max(heightOfAvl(root->left), heightOfAvl(root->right));

    // 3. Get the balance factor of the ancestor
    int balance = getBalanceFactor(root);

    // if balanced then simply return
    if (balance <= 1 && balance >= -1) {
        return root;
    }
    // printf("\n Unbalanced at %s\n", cust.mobNo);

    // if current AVL_Node is unbalanced, then
    // check for 4 cases

    // Left Left case
    // if (balance > 1 && cust.mobNo < root->left->cust.mobNo) {
    if (balance > 1 && stringCompare(cust.mobNo, root->left->cust.mobNo) < 0) {
        // printf("case1");
        return rightRotate(root);
    }

    // Right Right case
    // if (balance < -1 && cust.mobNo > root->right->cust.mobNo) {
    if (balance < -1 && stringCompare(cust.mobNo, root->right->cust.mobNo) > 0) {
        // printf("case2");
        return leftRotate(root);
    }

    // Left Right case
    // if (balance > 1 && cust.mobNo > root->left->cust.mobNo) {
    if (balance > 1 && stringCompare(cust.mobNo, root->left->cust.mobNo) > 0) {
        // printf("case3");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left case
    // if (balance < -1 && cust.mobNo < root->right->cust.mobNo) {
    if (balance < -1 && stringCompare(cust.mobNo, root->right->cust.mobNo) < 0) {
        // printf("case4");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVL_Node* inorderSucc(AVL_Node* root) {
    AVL_Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

AVL_Node* deleteAVL(AVL_Node* root, char* mobNo) {
    // Normal BST deletion
    if (root == NULL) {
        return NULL;
    }

    if (stringCompare(mobNo, root->cust.mobNo) < 0) {
        root->left = deleteAVL(root->left, mobNo);
    } else if (stringCompare(mobNo, root->cust.mobNo) > 0) {
        root->right = deleteAVL(root->right, mobNo);
    } else {
        // AVL_Node has no child
        if (root->left == NULL && root->right == NULL) {
            AVL_Node* toDel = root;
            free(toDel);
            nodesInAvl--;
            // printf("deleted");
            return NULL;
        }

        // AVL_Node with only one child or no child
        else if (root->left == NULL) {
            struct AVL_Node* temp = root->right;
            free(root);
            nodesInAvl--;
            // printf("deleted");
            return temp;
        } else if (root->right == NULL) {
            struct AVL_Node* temp = root->left;
            free(root);
            // printf("deleted");
            nodesInAvl--;
            return temp;
        }

        // AVL_Node with two children: Get the inorder successor
        // (smallest in the right subtree)
        AVL_Node* temp = inorderSucc(root->right);

        // Copy the inorder successor's content to this AVL_Node
        root->cust = temp->cust;

        // Delete the inorder successor
        root->right = deleteAVL(root->right, temp->cust.mobNo);
    }

    if (root == NULL) {
        return root;
    }

    // 2. Update heightOfAvl of ancestor AVL_Node
    root->heightOfAvl = max(heightOfAvl(root->left), heightOfAvl(root->right)) + 1;

    // 3. Get the balance factor of the ancestor
    int balance = getBalanceFactor(root);

    // if balanced then simply return
    if (balance <= 1 && balance >= -1) {
        return root;
    }

    // if current AVL_Node is unbalanced, then
    // check for 4 cases

    // Left Left case
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}

AVL_Node* getNode(AVL_Node* root, char mobNo[]){
    if(root == NULL){
        return NULL;
    }

    if(stringCompare(mobNo, root->cust.mobNo) == 0){
        return root;
    }else if(stringCompare(mobNo, root->cust.mobNo) < 0){
        return getNode(root->left, mobNo);
    }else if(stringCompare(mobNo, root->cust.mobNo) > 0){
        return getNode(root->right, mobNo);
    }
}

// void levelOrderTraversal(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     queue<AVL_Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty()) {
//         AVL_Node* curr = q.front();
//         q.pop();

//         if (curr) {
//             cout << curr->data << " ";
//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//         } else if (!q.empty()) {
//             q.push(NULL);
//             cout << endl;
//         }
//     }
// }

// void inorder(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }
//     inorder(root->left);
//     printf("%s ", root->cust.mobNo);
//     inorder(root->right);
// }

// void preorder(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }
//     printf("%s ", root->cust.mobNo);
//     fflush(stdout);
//     preorder(root->left);
//     preorder(root->right);
// }

// void postorder(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     printf("%s ", root->cust.mobNo);
//     fflush(stdout);
// }

// int main() {
//     AVL_Node* root = NULL;

//     // int arr[] = { 14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20 };
//     // int n = sizeof(arr) / sizeof(arr[0]);

//     char str1[] = "1111111111";
//     char str2[] = "2222222222";
//     char str3[] = "8766964749";
//     char str4[] = "8380927810";
//     char str5[] = "7654567325"; 

//     Customer cust1;
//     strcpy(cust1.mobNo, str1);
//     Customer cust2;
//     strcpy(cust2.mobNo, str2);
//     Customer cust3;
//     strcpy(cust3.mobNo, str3);
//     Customer cust4;
//     strcpy(cust4.mobNo, str4);
//     Customer cust5;
//     strcpy(cust5.mobNo, str5);
//     root = insertAVL(root, cust1);
//     root = insertAVL(root, cust2);
//     root = insertAVL(root, cust3);
//     root = insertAVL(root, cust4);
//     root = insertAVL(root, cust5);

//     printf("here\n\n");
//     inorder(root);
//     printf("\n\n");

//     printf("here\n\n");
//     postorder(root);
//     printf("\n\n");
//     return 0;
// }