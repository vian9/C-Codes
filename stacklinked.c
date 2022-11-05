#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
}typedef node;

struct node* makeNode(int val) {
    node* newNode = (node*) malloc(sizeof(struct node*));
    newNode->data = val;
    newNode->next = NULL;
    
    return newNode;
}

void push(node** head, int val) {
    node* newNode = makeNode(val);

    newNode->next = *head;
    *head = newNode;
}

void pop(node** head){
    if(*head == NULL){
        printf("No elements to pop!\n\n");
        return;
    }
    
    node* toDel = *head;
    *head = (*head)->next;
    free(toDel);
    printf("Element Popped!\n\n");
}

void display(node* head){
    if(head == NULL){
        printf("Nothing to display\n\n");
        return;
    }
    printf("Stack is: \n");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    } printf("\n\n");
}

void mainMenu() {
    printf("\n\t MAIN MENU\n");
    printf("Select from the following options: \n");
    printf("\t1. To Push\n");
    printf("\t2. To Pop\n");
    printf("\t3. To Display\n");
    printf("\t0. For Exit\n\n");
}

int main(){
    node* stack = NULL;
    
    mainMenu();

    int userInput;
    int element;
    bool forBreak;
    
    while (true) {
        printf("Select the option: ");
        scanf("%d", &userInput);
        forBreak = false;

        switch (userInput)
        {
        case 1:
            printf("Enter the number of elements to push: ");
            int n; scanf("%d", &n);
            printf("Enter %d element to push: ", n);
            for(int i = 0; i < n; i++){
                scanf("%d", &element);
                push(&stack, element);
            }
            printf("Elements pushed!\n\n");
            break;
        
        case 2:
            pop(&stack);
            break;
        case 3:
            display(stack);
            break;
        case 0:
        forBreak = true;
            printf("Program is closed\n\n");
            break;
        default:
            printf("Select proper option!\n\n");
            break;
        }
        if (forBreak) {
            break;
        }
    }
    return 0;
}