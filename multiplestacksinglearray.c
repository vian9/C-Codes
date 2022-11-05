#include <stdio.h>
#include <stdbool.h>
#define MAX 12

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int val){
    if(top1 + 1 == top2){
        printf("Stack1 OVERFLOW!!! Insertion is not possible!!!\n");
        return;
    }
    top1++;
    stack[top1] = val;
}

void push2(int val){
    if(top1 + 1 == top2){
        printf("Stack2 OVERFLOW!!! Insertion is not possible!!!\n");
        return;
    }
    top2--;
    stack[top2] = val;
}

void pop1() {
    if (top1 == -1) {
        printf("UNDERFLOW! In Stack1 Deletion is not possible!!\n");
        return;
    }
    top1--;
}

void pop2() {
    if (top2 == MAX) {
        printf("UNDERFLOW! In Stack2 Deletion is not possible!!\n");
        return;
    }
    top2++;
}

void traverse1(){
    printf("Stack1: ");
    int temp = top1;
    if(temp == -1){
        printf("Empty\n\n");
        return;
    }
    while(temp != -1){
        printf("%d ", stack[temp]);
        temp--;
    }
    printf("\n");
}

void traverse2(){
    printf("Stack2: ");
    int temp = top2;
    if(temp == MAX){
        printf("Empty\n\n");
        return;
    }
    while (temp != MAX)
    {
        printf("%d ", stack[temp]);
        temp++;
    }
    
    printf("\n");
}

int main(){
    printf("\n Stack size is 12\n");
    int n, input;
    bool run;
    run = true;
    do{
        printf("Number of Elements to be entered in Stack 1: ");
        scanf("%d", &n);

        if((top2 - top1 - 1)<n){
            printf("\nSpace Not Available, Only %d items can be inserted!\n\n", top2 - top1 - 1);
        } else{
            run=false;
            printf("Enter %d values: ",n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d",&input);
                push1(input);
            }
            printf("\n");
        }
    }  while (run == true);
    traverse1();
    run = true;
    do{
        printf("Number of Elements to be entered in Stack 2: ");
        scanf("%d", &n);
        if ((top2 - top1 - 1) < n)
        {
            printf("\nSpace Not available, Only %d items can be inserted!\n\n", top2 - top1 - 1);
        } else {
            run = false;
            printf("Enter %d values: ", n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &input);
                push2(input);
            }
            printf("\n");
        }   
    } while (run == true);
    traverse2();
    printf("Number of elements to pop in Stack 1: ");
    scanf("%d",&n);
    if (n > top1 + 2){
        n = top1 + 2;
    }
    for (int i = 0; i < n; i++){
        pop1();
    }
    traverse1();

    printf("Number of elements to pop in Stack 2: ");
    scanf("%d",&n);
    if (n > MAX - top2 + 1){
        n = MAX - top2 + 1;
    }
    for (int i = 0; i < n; i++){
        pop2();
    }
    traverse2();
    
}