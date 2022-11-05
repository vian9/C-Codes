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

void SLL_Insert_End(node** head, int val) {
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

void SLL_Insert_Beginning(node** head, int val) {
    node* newNode = makeNode(val);

    newNode->next = *head;
    *head = newNode;
}

void SLL_Insert_After(node** head, int val, int toInsert) {
    node* temp = *head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nElement not found!\n\n");
        return;
    }

    node* newNode = makeNode(toInsert);
    node* storeNext = temp->next;
    temp->next = newNode;
    newNode->next = storeNext;
    printf("\n Element Inserted successfully\n\n");
}

void deletion(node** head, int val) {
    node* temp = *head;
    if (temp == NULL) {
        printf("\nList is empty\n\n");
        return;
    }

    node* toDel = NULL;
    if (temp->data == val) {
        toDel = temp;
        temp = temp->next;
        *head = temp;
        free(toDel);
        printf("\nElement Deleted Successfully\n\n");
        return;
    }

    if (temp->next == NULL) {
        if (temp->data == val) {
            toDel = temp;
            temp = temp->next;
            *head = temp;
            free(toDel);
            printf("\nElement Deleted Successfully\n\n");
            return;
        }
        printf("\nNot found\n\n");
        return;
    }

    while (temp->next->data != val) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("\nNot found\n\n");
            return;
        }
    }
    toDel = temp->next;
    temp->next = temp->next->next;

    free(toDel);
    printf("\nElement Deleted Successfully\n\n");
}

void SLL_Delete_Beginning(node** head) {
    if (*head == NULL) {
        printf("\nNo value to Delete!\n\n");
        return;
    }

    node* toDel = *head;
    *head = (*head)->next;
    free(toDel);
    printf("\nElement at head deleted!\n\n");
}

void SLL_Delete_End(node** head) {
    if (*head == NULL) {
        printf("\nNo Element to Delete!\n\n");
        return;
    }

    node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    node* toDel = temp->next;
    temp->next = NULL;
    free(toDel);
    printf("\nValue at tail deleted!\n\n");
}

void SLL_Delete_After(node** head, int val) {
    if (head == NULL) {
        printf("\nList is empty\n\n");
        return;
    }

    node* temp = *head;
    while (temp->data != val && temp != NULL) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nValue not found\n\n");
        return;
    }

    if (temp->next == NULL) {
        printf("\nNo value after the element\n\n");
        return;
    }
    else {
        node* toDel = temp->next;
        temp->next = temp->next->next;
        free(toDel);
        printf("\nDeleted Successfully\n\n");
    }
}

void SLL_Display(node* head) {
    printf("Present State: ");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}

bool SLL_Search(node* head, int val) {
    while (head != NULL) {
        if (head->data == val) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void mainMenu() {
    printf("\nMain Menu \n");
    printf("Please Select One of the following Operations \n");
    printf("\t1. To Insert\n");
    printf("\t2. To Delete\n");
    printf("\t3. To Search\n");
    printf("\t4. To Display\n");
    printf("\t0. For Exit\n\n"); 
}

void menuInsert() {
    printf("\nPlease Select One type of insert function: \n");
    printf("\t1. Insert an Element at Beginning\n");
    printf("\t2. Insert an Element at End\n");
    printf("\t3. Insert after certain Element\n");
    printf("\t0. Back to Main Menu\n\n");
}

void menuDelete() {
    printf("\nPlease Select One type of delete function: \n");
    printf("\t1. Delete an Element at Beginning\n");
    printf("\t2. Delete an Element at End\n");
    printf("\t3. Delete certain value\n");
    printf("\t4. Delete after certain Element\n");
    printf("\t0. Back to Main \n\n");
}

int main() {

    node* head = NULL;

    mainMenu();
    int userInput;
    int insOpt;
    int element;
    bool forBreak = false;
    bool out;
    while (true) {     
        printf("Select the option: ");
        scanf("%d", &userInput);
        switch (userInput)
        {
        case 1:
            menuInsert();
            out = false;
            while (true) {
                SLL_Display(head);

                printf("Select the option: ");
                scanf("%d", &insOpt);

                if (insOpt == 1) {
                    printf("Enter the element to insert at Position head: ");
                    scanf("%d", &element);
                    SLL_Insert_Beginning(&head, element);
                    printf("Element inserted at head!\n");
                }
                else if (insOpt == 2) {
                    printf("Enter the number of elements to insert at Position tail: ");
                    int n; scanf("%d", &n);
                    printf("Enter the element:  ");
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &element);
                        SLL_Insert_End(&head, element);
                    }
                    printf("Elements inserted at tail!\n");
                }
                else if (insOpt == 3) {
                    printf("Enter the element to enter: ");
                    scanf("%d", &element);
                    printf("The element after which you want to insert: ");
                    int value; scanf("%d", &value);
                    SLL_Insert_After(&head, value, element);
                }
                else if (insOpt == 0) {
                    printf("Back to Main Menu\n\n");
                    mainMenu();
                    out = true;
                    break;
                }
                else {
                    printf("Select correct option\n");
                }

                if (out == true) {
                    break;
                }
            }
            break;
        case 2:
            menuDelete();

            out = false;
            while (true) {
                SLL_Display(head);

                printf("Select the option: ");
                scanf("%d", &insOpt);

                if (insOpt == 1) {
                    SLL_Delete_Beginning(&head);
                }
                else if (insOpt == 2) {
                    SLL_Delete_End(&head);
                }
                else if (insOpt == 3) {
                    printf("Enter the element to delete: ");
                    scanf("%d", &element);
                    deletion(&head, element);
                }
                else if(insOpt == 4){
                    printf("The element after which you want to delete: ");
                    scanf("%d", &element);
                    SLL_Delete_After(&head, element);
                }
                else if (insOpt == 0) {
                    printf("Back to Main Menu\n\n");
                    mainMenu();
                    out = true;
                    break;
                }
                else {
                    printf("Select proper option\n");
                }

                if (out == true) {
                    break;
                }
            }
            break;
        case 3:
            printf("Enter the element to Search: ");
            scanf("%d", &element);
            if(SLL_Search(head, element)){
                printf("\nElement Found!\n\n");
            } else {
                printf("\nElement Not found!\n\n");
            }
            break;
        case 4:
            SLL_Display(head);
            break;
        case 0:
            printf("Program is Closed\n");
            forBreak = true;
            break;
        default:
            printf("Please select proper option!\n");
        }

        if (forBreak) {
            break;
        }
    }

    return 0;
}
