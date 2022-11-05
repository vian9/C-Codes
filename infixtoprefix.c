#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

// Stack Code Over

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

void reverseIt(char* str){
    int n = strlen(str);
    char temp;
    for(int i = 0; i < n/2; i++){
        temp = str[n-1-i];
        str[n-1-i] = str[i];
        str[i] = temp;
    }
}

void infixToPrefix(char* str) {
    char outcm[100];
    int index = 0;

    reverseIt(str);

    for (int i = 0; str[i] != '\0'; i++) {

        char chr = str[i];

        if((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') || (chr >= '0' && chr <= '9')){
            outcm[index++] = chr;
        }
        else if(chr == ')'){
            push(')');
        }
        else if(chr == '('){
            while(!empty() && peek() != ')'){
                outcm[index++] = peek();
                pop();
            }
            pop();
        }
        else {
            while(!empty() && prec(chr) < prec(peek())){
                outcm[index++] = peek();
                pop();
            }
            push(chr);
        }
    }

    while(!empty()){
        outcm[index++] = peek();
        pop();
    }

    outcm[index] = '\0';

    reverseIt(outcm);

    printf("%s", outcm);
}

int main() {
    char str[100];

    printf("\n\nEnter the string: ");
    scanf("%s", &str);
    
    printf("\nPrefix is: ");
    infixToPrefix(str);

    printf("\n\n");
}