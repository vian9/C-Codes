#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
}typedef node;

struct node* makeNode(int val) {
    node* newNode = (node*)malloc(sizeof(struct node*));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

node* head = NULL;
node* st = NULL;

void SLL_Insert_End(int val) {
    node* newNode = makeNode(val);

    node* temp = head;
    if (temp == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SLL_Display() {
    printf("List: ");
    node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

void push(int val) {
    node* newnode = makeNode(val);
    newnode->next = st;
    st = newnode;
}

void pop(){
    if(st == NULL){
        printf("No elements to pop!\n\n");
        return;
    }
    node* toDel = st;
    st = st->next;
    free(toDel);
    printf("Value Popped!\n\n");
}

void displayStack(){
    if(st == NULL){
        printf("Nothing to SLL_Display\n\n");
        return;
    }
    printf("Stack is: \n");

    node* temp = st;
    while(temp != NULL){
        printf("%d ", (temp->data));
        temp = temp->next;
    } printf("\n\n");
}

int main(){
    int m;
    printf("\nEnter the number of Elements to be Inserted: ");
    scanf("%d",&m);
    int x;
    printf("\nEnter the values:");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        SLL_Insert_End(x);
    }
    SLL_Display();

    int rev;
    printf("\nEnter the number till where the List is to Reversed: ");
    scanf("%d",&rev);

    for(int i = 0; i < rev; i++){
        push(head->data);
        node* toDel = head;
        head = head->next;
        free(toDel);
    }

    node* newHead = st;
    node* temp = newHead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head = newHead;
    SLL_Display();
    
    return 0;
}