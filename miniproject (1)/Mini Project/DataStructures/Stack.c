#include <stdio.h>

#include "LinkedList.c"

void pushInStack(SLL_Node** head, int amt, char* desc, bool paid){
    insertAtHead(head, amt, desc, paid);
    fflush(stdout);
}

void popInStack(SLL_Node** stack){
    deleteAtHead(stack);
}

void displayStack(SLL_Node* stack){
    displayLL(stack);
}

void payDue(Customer cust){
    SLL_Node* temp = cust.stack;

    while(temp != NULL){
        temp->paid = true;
        temp = temp->next;
    }
}

// int main() {
//     SLL_Node* stack = NULL;
//     char str1[] = "GROCERIES";
//     pushInStack(&stack, 100, str1, true);
//     char str2[] = "FRUITS";
//     pushInStack(&stack, 500, str2, false);
//     displayStack(stack);

//     return 0;
// }