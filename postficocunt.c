#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char val) {
    if (top == (MAX - 1)) {
        printf("Stack OVERFLOW!!! Insertion is not possible!!!\n");
        return;
    }
    top++;
    stack[top] = val;
}

void pop() {
    if (top == -1) {
        printf("UNDERFLOW! Deletion is not possible!!\n");
        return;
    }
    top--;
}

int peek() {
    if (top == -1) {
        printf("EMPTY! Nothing to peek!!\n");
        return -1;
    }
    return stack[top];
}

int power(int base, int pow) {
    int ans = 1;
    while (pow--) {
        ans *= base;
    }
    return ans;
}

void postfixEvaluation(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char curr = str[i];
        if (curr >= '0' && curr <= '9') {
            push(curr - '0');
        }
        else {
            int op2 = peek();
            pop();
            int op1 = peek();
            pop();

            switch (curr) {
            case '^':
                push(power(op1, op2));
                break;
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            default:
                printf("Invalid Operator!\n\n");
                exit(0);
                break;
            }
        }
    }

    printf("Value of expression is %d\n \n", peek());
}

int main() {
    printf("\nEnter Postfix expression: ");
    char str[100];
    scanf("%s", &str);

    postfixEvaluation(str);

    return 0;
}