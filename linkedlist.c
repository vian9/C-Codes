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

void insertAtTailPos(node** head, int val) {
    node* newNode = makeNode(val);

    node* temp = *head;
    if (temp == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHeadPos(node** head, int val) {
    node* newNode = makeNode(val);

    newNode->next = *head;
    *head = newNode;
}

void insertAfter(node** head, int val, int toInsert){
    node* temp = *head;
    while(temp->data != val && temp != NULL){
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }

    node* newNode = makeNode(toInsert);
    node* storeNext = temp->next;
    temp->next = newNode;
    newNode->next = storeNext;
}

void deletion(node** head, int val) {
    node* temp = *head;
    if (temp == NULL) {
        return;
    }

    node* toDel = NULL;
    if (temp->data == val) {
        toDel = temp;
        temp = temp->next;
        *head = temp;
        free(toDel);
        return;
    }

    if (temp->next == NULL) {
        if (temp->data == val) {
            toDel = temp;
            temp = temp->next;
            *head = temp;
            free(toDel);
            return;
        }
        return;
    }

    while (temp->next->data != val) {
        temp = temp->next;
        if (temp->next == NULL) {
            return;
        }
    }
    toDel = temp->next;
    temp->next = temp->next->next;

    free(toDel);
}

void deleteAtHeadPos(node** head){
    if(*head == NULL){
        return;
    }

    node* toDel = *head;
    *head = (*head)->next;
    free(toDel);
}

void deleteAtTailPos(node** head){
    if(*head == NULL){
        return;
    }

    node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    node* toDel = temp->next;
    temp->next = NULL;
    free(toDel);
}

void deleteAfter(node** head, int val){
    if(head == NULL){
        return;
    }

    node* temp = *head;
    while(temp->data != val && temp != NULL){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    if(temp->next == NULL){
        return;
    }else{
        node* toDel = temp->next;
        temp->next = temp->next->next;
        free(toDel);
    }
}

void display(node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

bool search(node* head, int val){
    while(head != NULL){
        if(head->data == val){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main() {

    node* head = NULL;
    int m;
    printf("\nEnter the number of Elements to be Inserted at Tail : ");
    scanf("%d",&m);
    int x;
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        insertAtTailPos(&head, x);
    }

    int n;
    printf("\nEnter the number of Elements to be Inserted at Head : ");
    scanf("%d",&n);
    int y;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&y);
        insertAtHeadPos(&head, y);
    }

    display(head);

    insertAfter(&head, 2, 10);
    display(head);

    deleteAtHeadPos(&head);
    display(head);

    deleteAtTailPos(&head);
    display(head);

    deleteAfter(&head, 2);
    display(head);

    deletion(&head, 4);
    display(head);

    printf("%d\n", search(head, 1));
    printf("%d\n", search(head, 5));
}