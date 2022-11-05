#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
} typedef node;

node* front = NULL;
node* rear = NULL;

node* makeNode(int val){
    node* newNode = (struct node*) malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void enQueue(int val){
    node* newNode = makeNode(val);

    if(newNode == NULL){
        printf("Queue is FULL!!!, Insertion is not possible!!!\n");
        return;
    }

    if(rear == NULL){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}

bool deQueue(){
    if(front == NULL){
        printf("Queue is EMPTY! Deletion is not possible!\n");
        return false;
    }else if(front == rear){
        front = NULL;
        rear = NULL;
        return true;
    }else{
        node* toDel = front;
        front = front->next;
        free(toDel);
        return true;
    }
}

void display(){
    if(front == NULL){
        printf("Queue is EMPTY!!!\n");
    }else{
        printf("Queue is: ");
        node* temp = front;

        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        fflush(stdout);
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

int main() {
    int num, x;
    printf("\n\nQUEUE USING LINKED LIST\n\n");
    menu();

    while (1) {
        printf("\nEnter your option you choose from Menu: ");

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
            printf("\nPlease Choose the right option!");
        }
    }
}