#include <stdio.h>
#define deb(x) printf("%s = %d\n", #x, x);
#define MAX 100

void push(int* stack, int* top, int val){

    if((*top) == MAX-1){
        printf("Stack OVERFLOW!!! Insertion is not possible!!!\n");
        return;
    }

    (*top)++;
    stack[*top] = val;
}

void pop(int* stack, int* top){
    if((*top) == -1){
        printf("UNDERFLOW! Deletion is not possible!\n");
        return;
    }

    (*top) = (*top) - 1;
}

void traverse(int* stack, int top){
    if(top == -1){
        printf("UNDERFLOW! There are no elements to display!\n");
        return;
    }

    int k = top;
    while(k >= 0){
        printf("%d ", stack[k]);
        k--;
    }
    printf("\n");
}

int main(){
    int stack[MAX];
    int top = -1;


    int n;
    printf("Enter number of elements to enter: ");
    scanf("%d", &n);

    printf("Enter values of elements: ");
    for(int i = 0; i < n; i++){
        int values;
        scanf("%d", &values);
        push(stack, &top, values);
    }

    printf("Your entered stack is: ");
    traverse(stack, top);

    int forpop;
    printf("\nEnter number of values to pop: ");
    scanf("%d", &forpop);

    for(int i = 0; i < forpop; i++){
        pop(stack, &top);
    }

    printf("\nFinal Stack after popping: ");
    traverse(stack, top);

    return 0;
}