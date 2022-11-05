#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Avl.c"

// typedef struct SLL_Node {
//     Customer* custPtr;
//     struct SLL_Node* next;
//     int Amount;
//     char productDescription[30];
// } SLL_Node;

SLL_Node* newNode(int amt, char* desc, bool paid) {
    SLL_Node* new_node = (SLL_Node*)malloc(sizeof(SLL_Node));
    if(new_node == NULL){
        printf("\n\t\t **MEMORY EXHAUSTED can't perform further operations!**\n\n");
        return NULL;
    }
    new_node->next = NULL;
    new_node->Amount = amt;
    strcpy(new_node->productDescription, desc);
    new_node->paid = paid;
    getDate(new_node->date);
    return new_node;
}

void insertAtHead(SLL_Node** head, int amt, char* desc, bool paid) {
    SLL_Node* new_node = newNode(amt, desc, paid);
    new_node->next = *head;
    *head = new_node;
}

void insertAtTail(SLL_Node** head, int amt, char* desc, bool paid) {
    SLL_Node* new_node = newNode(amt, desc, paid);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    SLL_Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void deleteAtHead(SLL_Node** head) {
    if (*head == NULL) {
        return;
    }
    SLL_Node* toDel = *head;
    *head = (*head)->next;
    free(toDel);
}

void deleteAtTail(SLL_Node** head) {
    if (*head == NULL) {
        return;
    }

    SLL_Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while ((temp)->next->next != NULL) {
        temp = (temp)->next;
    }

    SLL_Node* toDel = (temp)->next;
    temp->next = NULL;
    free(toDel);
}

void displayLL(SLL_Node* head) {
    if (head == NULL) {
        printf("\nEmpty!\n");
        return;
    }
    
    // printf("\n\t\t\t\t               *** TRANSACTION HISTORY ***\n\n");
    printf("\t\t\t\t|------------------------------------------------------------------|\n");
    printf("\t\t\t\t| %-8s | %-25s | %-13s |  %-8s |\n", "Amount", "Product Description", "Date", "STATUS");
    printf("\t\t\t\t|------------------------------------------------------------------|\n");
    
    while (head != NULL) {
        char pDate[20];
        strcpy(pDate, head->date);
        extractDate(pDate);
        if (head->paid == true) {
            printf("\t\t\t\t| %-8d | %-25s | %-13s |  %-8s |\n", head->Amount, head->productDescription, pDate, "PAID");
        } else {
            printf("\t\t\t\t| %-8d | %-25s | %-13s |  %-8s |\n", head->Amount, head->productDescription, pDate, "UNPAID");
        }
        head = head->next;
    }
    printf("\t\t\t\t|------------------------------------------------------------------|\n");
    printf("\n");
}

// int main() {
//     SLL_Node* head = NULL;
//     char str1[] = "GROCERIES";
//     insertAtHead(&head, 100, str1, true);

//     char str2[] = "FRUITS";
//     insertAtTail(&head, 500, str2, false);
//     displayLL(head);

//     // insertAtTail(&head, arr[i]);

//     return 0;
// }