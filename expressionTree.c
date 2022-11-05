#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node typedef node;
struct node {
    char val;
    node* left, * right;
};

#define MAX 100

node* stack[MAX];
int top = -1;

void push(node* data) {
    if (top == MAX - 1) {
        printf("STACK OVERFLOW!\n");
        return;
    }

    top++;
    stack[top] = data;
}

void pop() {
    if (top == -1) {
        printf("STACK IS EMPTY!\n");
        return;
    }
    top--;
}

node* getTop() {
    if (top == -1) {
        return NULL;
    }
    return stack[top];
}

void traverse() {
    if (top == -1) {
        printf("NOTHING TO DISPLAY!\n");
        return;
    }
    printf("Stack is: ");
    for (int t = top; t >= 0; t--) {
        printf("%d ", stack[t]);
    }printf("\n");
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

node* newNode(char value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->val = value;
    return temp;
};

node* constructTree(char postfix[]) {
    node* root, * operand1, * operand2;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            root = newNode(postfix[i]);
            push(root);
        } else {
            root = newNode(postfix[i]);

            operand1 = getTop();
            pop();

            operand2 = getTop();
            pop();

            root->right = operand1;
            root->left = operand2;

            push(root);
        }
    }

    root = getTop();
    pop();

    return root;
}

void inorder(node* root){
    if(!root){
        return;
    }

    inorder(root->left);
    printf("%c ", root->val);
    inorder(root->right);
}

void preorder(node* root){
    if(!root){
        return;
    }

    printf("%c ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(!root){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->val);
}

int main() {
    char postfix[100];
    printf("\n\nEnter the Postfix string: ");
    scanf("%s", postfix);

    node* root = constructTree(postfix);

    printf("\nInorder    = ");
    inorder(root); printf("\n");

    printf("Preorder   = ");
    preorder(root); printf("\n");
    
    printf("Postorder  = ");
    postorder(root); printf("\n");
    printf("\n\n");
    return 0;
}