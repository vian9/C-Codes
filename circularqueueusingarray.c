#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enQueue(int val){
    if((rear == SIZE-1 && front == 0) || (front == rear+1)){
        printf("Queue is FULL!!! Insertion is not possible!!!\n");
    }else{
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }
}

bool deQueue(){
    if(front == -1){
        printf("Queue is EMPTY! Deletion is not possible!\n");
        return false;
    }else{
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % SIZE;
        }
        return true;
    }
}

void menu() {
    printf("\n Please Select the Option from the Menu: \n");
    printf("\n 1. To ENQUE");
    printf("\n 2. To DEQUE");
    printf("\n 3. To DISPLAY QUEUE");
    printf("\n 4. To MENU");
    printf("\n 5. To EXIT\n\n");
}

void display(){
    if(front == -1){
        printf("Queue is EMPTY!!!\n");
    }else{
        printf("Queue is: ");
        int run = front;
        while(run != rear){
            printf("%d ", queue[run]);
            run = (run + 1) % SIZE;
        }
        printf("%d", queue[run]);
        printf("\n");
    }
}

int main() {
    int num, x;
    printf("\n\nCIRCULAR QUEUE USING ARRAYS\n\n");
    menu();

    while (1) {
        printf("\nEnter your option you choose from the Menu: ");

        scanf("%d", &num);
        switch (num) {
        case 1:
            printf("\nEnter the number of values to ENQUE: ");
            scanf("%d", &x);
            printf("Enter %d values: ", x);
            int inpt;
            for(int i = 0; i < x; i++){
                scanf("%d", &inpt);
                enQueue(inpt);
            }
            break;
        case 2:
            printf("\nEnter the number of values to DEQUE: ");
            scanf("%d", &x);
            for(int i = 0; i < x; i++){
                if(deQueue() == false){
                    break;
                }
            }
            break;
        case 3:
            display();
            break;
        case 4:
            menu();
            break;
        case 5:
            exit(0);
        default:
            printf("\nPlease choose the right option!");
        }
    }
}