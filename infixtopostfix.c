#include <stdio.h>
#include <stdbool.h>

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

bool empty() {
    if (top == -1) {
        return true;
    }
    return false;
}

char peek() {
    if (top == -1) {
        printf("EMPTY! Nothing to peek!!\n");
        return '!';
    }
    return stack[top];
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char* strg) {
    char result[100];
    int index = 0;

    for (int i = 0; strg[i] != '\0'; i++) {
        
        char curr = strg[i];

        if((curr >= 'a' && curr <= 'z') || (curr >= 'A' && curr <= 'Z') || (curr >= '0' && curr <= '9')){
            result[index++] = curr;
        }
        else if(curr == '('){
            push('(');
        }
        else if(curr == ')'){
            while(peek() != '('){
                result[index++] = peek();
                pop();
            }
            pop();
        }
        else {
            if(curr == '^'){
                push(curr);
            }else{
                while (!empty() && prec(peek()) >= prec(curr)) {
                    result[index++] = peek();
                    pop();
                }
                push(curr);
            }
        }
    }

    while (!empty()) {

        result[index++] = peek();
        pop();
    }
    result[index] = '\0';

    printf("%s \n", result);
}

int main() {
    char strg[100];

    printf("\nEnter string: ");
    scanf("%s", &strg);

    printf("Postfix: ");
    infixToPostfix(strg);
}