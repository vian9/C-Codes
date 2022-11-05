#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void push(char* stack, int* top, char val){

    if((*top) == MAX-1){
        printf("Stack OVERFLOW!!! Insertion is not possible!!!\n");
        return;
    }

    (*top)++;
    stack[*top] = val;
}

void pop(char* stack, int* top){
    if((*top) == -1){
        printf("UNDERFLOW! Deletion is not possible!!\n");
        return;
    }

    (*top) = (*top) - 1;
}

bool empty(char* stack, int top){
    if(top == -1){
        return true;
    }
    return false;
}

char peek(char* stack, int top){
    if(top == -1){
        printf("EMPTY! Nothing to peek!!\n");
        return '!';
    }
    return stack[top];
}

bool Paranthesis_Balance(char *str, char* stack, int* top){
    
    for(int i = 0; str[i] != '\0'; i++){
        char curr = str[i];

        if(curr == '(' || curr == '[' || curr == '{'){
            if(curr == '('){
                push(stack, &(*top), ')');
            }else if(curr == '['){
                push(stack, &(*top), ']');
            }else if(curr == '{'){
                push(stack, &(*top), '}');
            } 
        }else if(curr == ')' || curr == ']' || curr == '}'){
            if(curr == ')'){
                if(!empty(stack, (*top)) && peek(stack, (*top)) == curr){
                    pop(stack, &(*top));
                }else{
                    return false;
                }
            }
            else if(curr == ']'){
                if(!empty(stack, (*top)) && peek(stack, (*top)) == curr){
                    pop(stack, &(*top));
                }else{
                    return false;
                }
            }
            else if(curr == '}'){
                if(!empty(stack, (*top)) && peek(stack, (*top)) == curr){
                    pop(stack, &(*top));
                }else{
                    return false;
                }
            }
        }
    }

    if(empty(stack, (*top))){
        return true;
    }

    return false;
}

int main(){
    char stack[MAX];
    int top = -1;

    printf("Enter the length of  string: ");
    int n; scanf("%d", &n);

    fflush(stdin);
    char str[n];
    printf("\nEnter the paranthesis string: ");
    scanf("%s", &str);
    fflush(stdin);

    bool check = Paranthesis_Balance(str, stack, &top);

    if(check){
        printf("Parenthesis are Balanced.\n");
    }else{
        printf("Parenthesis are Not Balanced.\n");
    }
}