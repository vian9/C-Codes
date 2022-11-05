#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node typedef node;

struct node* head = NULL;

node* makeNode(int val){
    node* newNode = (node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void DLL_Display(){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }printf("NULL\n");
}

void DLL_Insert_Beginning(int val){
    node* newNode = makeNode(val);
    
    if(head == NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DLL_Insert_End(int val){
    node* newNode = makeNode(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void DLL_Insert_After(int val, int after){
    if(head == NULL){
        return;
    }

    node* newNode = makeNode(val);

    node* temp = head;
    while(temp!= NULL && temp->data != after){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    if(temp->next != NULL){
        node* storeNext = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = storeNext;
        storeNext->prev = newNode;
    } else {
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DLL_Insert_Before(int val, int before){
    if(head == NULL){
        return;
    }

    node* newNode = makeNode(val);

    if(head->data == before){
        DLL_Insert_Beginning(val);
    }

    node* temp = head;
    while(temp->next!= NULL && temp->next->data != before){
        temp = temp->next;
    }

    if(temp->next == NULL){
        return;
    }

    node* storeNext = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = storeNext;
    storeNext->prev = newNode;
}

void DLL_Delete_Beginning(){
    if(head == NULL){
        return;
    }
    node* toDel = head;
    head = head->next;
    head->prev = NULL;
    free(toDel);
}

void DLL_Delete_End(){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        node* toDel = head;
        head = NULL;
        free(toDel);
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* toDel = temp;
    temp->prev->next = NULL;
    free(toDel);
}

void DLL_Delete_After(int after){
    if(head == NULL){
        return;
    }

    node* temp = head;
    while(temp != NULL && temp->data != after){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    if(temp->next == NULL){
        return;
    }

    node* toDel = temp->next;
    node* nextNode = temp->next->next;
    if(nextNode != NULL){
        temp->next = nextNode;
        nextNode->prev = temp;
    }else{
        temp->next = nextNode;
    }
    free(toDel);
}

void DLL_Delete_Before(int before){
    if(head == NULL){
        return;
    }
    if(head->data == before){
        return;
    }

    node* temp = head;
    while(temp != NULL && temp->data != before){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    node* toDel = temp->prev;
    node* prevNode = temp->prev->prev;
    if(prevNode != NULL){
        prevNode->next = temp;
        temp->prev = prevNode;
    }else{
        temp->prev = prevNode;
    }
}

void DLL_Delete_Value(int val){
    if(head == NULL){
        return;
    }
    
    if(head->data == val){
        DLL_Delete_Beginning();
        return;
    }

    node* temp = head;
    while(temp != NULL && temp->data != val){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    if(temp->next == NULL){
        DLL_Delete_End();
    }else{
        node* toDel = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(toDel);
    }
}

bool DLL_Search(int val){
    if(head == NULL){
        return false;
    }

    node* temp = head;
    while(temp != NULL){
        if(temp->data == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    int m;
    printf("\nEnter the number of Elements to be Inserted at End : ");
    scanf("%d",&m);
    int x;
    printf("\nEnter the values:");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        DLL_Insert_End(x);
    }
    DLL_Display();

    printf("\nEnter the number of Elements to be Inserted at Beginning : ");
    scanf("%d",&m);
    printf("\nEnter the values:");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        DLL_Insert_Beginning(x);
    }
    DLL_Display();

    printf("\nEnter the Element After which to be Inserted: ");
    scanf("%d",&m);
    printf("\nEnter the number of Value of Elements to be Inserted: ");
    scanf("%d",&x);
    DLL_Insert_After(x, m);
     DLL_Display();
    printf("\nEnter the Element Before which to be Inserted : ");
    scanf("%d",&m);
    printf("\nEnter the number of Value of Elements to be Inserted: ");
    scanf("%d",&x);
    DLL_Insert_Before(x, m);
    DLL_Display();


    printf("\nPress 1 or 2 to Delete at Beginning or End Respectively or 3 for both: ");
    scanf("%d",&m);
    if (m==1){
        DLL_Delete_Beginning();
    } else if (m==2)
    {
        DLL_Delete_End();
    }
    else {
        DLL_Delete_Beginning();
        DLL_Delete_End();
    }
    DLL_Display();

    printf("\nEnter the Element After which to be Deleted: ");
    scanf("%d",&m);
    DLL_Delete_After(m);
    DLL_Display();
    printf("\nEnter the Element Before which to be Deleted : ");
    scanf("%d",&m);
    DLL_Delete_Before(m);
    DLL_Display();

    printf("\nEnter the Element Value to be Deleted: ");
    scanf("%d",&m);
    DLL_Delete_Value(m);
    DLL_Display();

    printf("\nEnter the Element Value to be Searched: ");
    scanf("%d",&m);
    if(DLL_Search(m)){
        printf("\nFound\n");
    }else {
        printf("\nNot Found\n");
    }

    DLL_Display();

    return 0;
}