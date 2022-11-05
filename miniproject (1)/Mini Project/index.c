#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "DataStructures/Stack.c"

AVL_Node* root = NULL;

void showCust(Customer cust) {
    if (cust.dueAmount == 0) {
        printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", cust.firstName, cust.lastName, cust.mobNo, cust.adress, cust.registeredDate, "NIL");
    } else {
        printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11d |\n", cust.firstName, cust.lastName, cust.mobNo, cust.adress, cust.registeredDate, cust.dueAmount);
    }
    fflush(stdin); fflush(stdout);
}

void printInInorderFashion(AVL_Node* root) {
    if (root == NULL) {
        return;
    }
    printInInorderFashion(root->left);
    showCust(root->cust);
    printInInorderFashion(root->right);
}

void registerCustomer() {
    printf("\n\n\t\t\t\t*********************** REGISTRATION *********************** \n");
    printf("\n\t\t\t\tEnter the details of the Customer-> \n\n");
    Customer newCust;
    char firstName[20];
    char lastName[20];
    char adress[100];
    // store mobno confidentially
    char mobNo[20];
    // int paidAmount;
    int dueAmount;
    char date[25];

    fflush(stdin);
    printf("\t\t\t\t\t    First name   : ");
    scanf("%[^\n]", &firstName);
    fflush(stdin);
    printf("\t\t\t\t\t    Last name    : ");
    scanf("%[^\n]", &lastName);
    fflush(stdin);
    printf("\t\t\t\t\t    Address      : ");
    scanf("%[^\n]", &adress);
    fflush(stdin);

    // Mob No input:
    bool first = true;
    while (true) {
        fflush(stdin);
        if (first) {
            printf("\t\t\t\t\t    Mobile No    : ");
            first = false;
        } else {
            printf("\t\t\t\t\t    Enter valid Mobile No : ");
        }
        scanf("%[^\n]", &mobNo);
        bool check = checkNumber(mobNo);
        if (check) {
            break;
        }
    }
    strcpy(newCust.mobNo, mobNo);
    fflush(stdin);

    char currDate[31];
    getDate(currDate);
    extractDate(currDate);
    strcpy(date, currDate);
    

    formatName(firstName);
    formatName(lastName);
    formatName(adress);

    strcpy(newCust.firstName, firstName);
    strcpy(newCust.lastName, lastName);
    strcpy(newCust.adress, adress);
    strcpy(newCust.registeredDate, date);

    dueAmount = 0;
    newCust.dueAmount = dueAmount;

    newCust.stack = NULL;
    fflush(stdin); fflush(stdout);

    int before = nodesInAvl;
    root = insertAVL(root, newCust);
    int after = nodesInAvl;

    if (after == before) {
        printf("\n\t\t\t\t               YOU ARE ALREADY REGISTERED!");
    } else if (after = before + 1) {
        printf("\n\t\t\t\t     ~~ HELLO \"%s\" you are REGISTERED SUCCESSFULLY! ~~", firstName);
    }
    printf("\n\n\t\t\t\t============================================================ \n");
}

void updateCustomer() {
    printf("\n\n\t\t\t\t************************* UPDATION ************************* \n");

    printf("\n\t\t\t\tEnter the details of the Customer-> \n\n");
    char phoneNo[14];

    bool first = true;
    while (true) {
        fflush(stdin);
        if (first) {
            printf("\t\t\t\t\t    Mobile No: ");
            first = false;
        } else {
            printf("\t\t\t\t\t    Enter valid Mobile No: ");
        }
        scanf("%[^\n]", &phoneNo);
        bool check = checkNumber(phoneNo);
        if (check) {
            break;
        }
    }
    fflush(stdin); fflush(stdout);
    AVL_Node* temp = getNode(root, phoneNo);

    Customer currCust;

    if (temp == NULL) {
        printf("\n\t\t\t\tERROR: No Customer found corresponding to number %s", phoneNo);;
    } else {
        currCust = temp->cust;
        printf("\n\tCURRENT CUSTOMER DETAILS: \n");
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
        printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", "FIRST NAME", "LAST NAME", "MOB NO.", "ADDRESS", "REG DATE", "DUE AMOUNT");
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
        showCust(temp->cust);
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");

        printf("\n\t\t\tPress 1 to CONFIRM OR any other key to CANCEL operation: \n\n");
        fflush(stdin);
        char ch;

        // Update name
        printf("\t\t   UPDATE NAME?   CHOICE: ");
        scanf("%c", &ch);
        fflush(stdin);
        if (ch == '1') {
            char firstName[25], lastName[25];
            printf("\t\t\t\t\t    First name   : ");
            scanf("%[^\n]", &firstName);
            fflush(stdin);
            printf("\t\t\t\t\t    Last name    : ");
            scanf("%[^\n]", &lastName);
            fflush(stdin);
            formatName(firstName);
            formatName(lastName);

            strcpy(temp->cust.firstName, firstName);
            strcpy(temp->cust.lastName, lastName);
            printf("\n\t\t\t\t           ~~ NAME UPDATED to \"%s\" SUCCESSFULLY! ~~\n\n", firstName);
        } else {
            printf("\n\t\t\t\t\t\t~~ NAME NOT UPDATED ~~\n\n");
        }

        // Update address
        printf("\t\t   UPDATE ADDRESS?   CHOICE: ");
        scanf("%c", &ch);
        fflush(stdin);
        if (ch == '1') {
            char address[25];
            printf("\t\t\t\t\t    Address      : ");
            scanf("%[^\n]", &address);

            formatName(address);

            strcpy(temp->cust.adress, address);
            printf("\n\t\t\t\t              ~~ ADDRESS UPDATED SUCCESSFULLY! ~~\n\n");
        } else {
            printf("\n\t\t\t\t\t\t~~ ADDRESS NOT UPDATED ~~\n\n");
        }

        fflush(stdout); fflush(stdin);

        // Update mobNo.
        printf("\t\t   UPDATE MOB NO.?   CHOICE: ");
        scanf("%c", &ch);
        fflush(stdin);
        if (ch == '1') {
            char mobNo[25];
            // Mob No input:
            bool first = true;
            while (true) {
                if (first) {
                    printf("\t\t\t\t\t    Mobile No    : ");
                    first = false;
                } else {
                    printf("\t\t\t\t\t    Enter valid Mobile No : ");
                }
                fflush(stdout);
                scanf("%[^\n]", &mobNo);
                fflush(stdin);
                bool check = checkNumber(mobNo);
                if (check) {
                    break;
                }
            }

            char oldNumber[15];
            strcpy(oldNumber, temp->cust.mobNo);
            
            Customer newCust;

            strcpy(newCust.firstName, temp->cust.firstName);
            strcpy(newCust.lastName, temp->cust.lastName);
            strcpy(newCust.mobNo, mobNo);
            strcpy(newCust.adress, temp->cust.adress);
            strcpy(newCust.registeredDate, temp->cust.registeredDate);
            newCust.dueAmount = temp->cust.dueAmount;
            newCust.stack = temp->cust.stack;

            currCust = newCust;

            root = deleteAVL(root, oldNumber);

            int before = nodesInAvl;
            root = insertAVL(root, newCust);
            int after = nodesInAvl;

            if (after == before) {
                printf("\n\t\t\t\t           THIS MOB NO. IS ALREADY REGISTERED!\n\n");
            } else if (after = before + 1) {
                printf("\n\t\t\t\t              ~~ MOB NO. UPDATED SUCCESSFULLY! ~~\n\n");
            }
        } else {
            printf("\n\t\t\t\t\t\t~~ MOB NO. NOT UPDATED ~~\n\n");
        }
    }

    printf("\n\tUPDATED CUSTOMER DETAILS: \n");
    printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
    printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", "FIRST NAME", "LAST NAME", "MOB NO.", "ADDRESS", "REG DATE", "DUE AMOUNT");
    printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
    showCust(currCust);
    printf("      |-----------------------------------------------------------------------------------------------------------------|\n");

    printf("\n\t\t\t\t       ~~ ALL THE CHANGES ARE SUCCESSFULLY UPDATED! ~~\n");

    printf("\n\n\t\t\t\t============================================================ \n");
}

void deleteCustomer() {
    printf("\n\n\t\t\t\t************************* DELETION ************************* \n");
    printf("\n\t\t\t\tEnter the details of the Customer-> \n\n");
    char phoneNo[14];

    bool first = true;
    while (true) {
        fflush(stdin);
        if (first) {
            printf("\t\t\t\t\t    Mobile No: ");
            first = false;
        } else {
            printf("\t\t\t\t\t    Enter valid Mobile No: ");
        }
        scanf("%[^\n]", &phoneNo);
        bool check = checkNumber(phoneNo);
        if (check) {
            break;
        }
    }
    fflush(stdin); fflush(stdout);
    AVL_Node* temp = getNode(root, phoneNo);

    if (temp == NULL) {
        printf("\n\t\t\t\tERROR: No Customer found corresponding to number %s", phoneNo);;
    } else {
        printf("\n\tCUSTOMER DETAILS: \n");
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
        printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", "FIRST NAME", "LAST NAME", "MOB NO.", "ADDRESS", "REG DATE", "DUE AMOUNT");
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
        showCust(temp->cust);
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");

        if (temp->cust.dueAmount != 0) {
            printf("\n\t\t\t\tWARNING: Customer %s has %d Due Amount\n", temp->cust.firstName, temp->cust.dueAmount);
        }
        printf("\n\t\t\tPress 1 to CONFIRM OR any other key to CANCEL deletion: ");
        fflush(stdin);
        char ch;
        scanf("%c", &ch);
        if (ch == '1') {
            char name[30];
            strcpy(name, temp->cust.firstName);
            root = deleteAVL(root, phoneNo);
            printf("\n\t\t\t\t         ~~ CUSTOMER \"%s\" is DELETED SUCCESSFULLY! ~~", name);
        } else {
            printf("\n\t\t\t\t\t\t~~ DELETION CANCELLED! ~~");
        }
    }
    printf("\n\n\t\t\t\t============================================================ \n");
}

void displayAllCustomers() {
    printf("\n\t\t\t\t  ******************* REGISTERED CUSTOMERS *******************\n\n");
    if (root == NULL) {
        printf("\n\t\t\t\t      ------------------ DATABASE EMPTY ------------------\n\n");
    } else {
        printf("     TOTAL CUSTOMERS: %d\n", nodesInAvl);
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
        printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", "FIRST NAME", "LAST NAME", "MOB NO.", "ADDRESS", "REG DATE", "DUE AMOUNT");
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
        printInInorderFashion(root);
        printf("      |-----------------------------------------------------------------------------------------------------------------|\n");
    }
    printf("\n\t\t\t\t  ============================================================ \n");
    fflush(stdout);
}

void buyProduct() {
    printf("\n\n\t\t\t\t*********************** BUY PRODUCTS *********************** \n");
    printf("\n\t\t\t\tEnter the details of the Customer-> \n\n");

    fflush(stdin);
    char mobNo[15];
    bool first = true;
    while (true) {
        fflush(stdin);
        if (first) {
            printf("\t\t\t\t\t    Mobile No: ");
            first = false;
        } else {
            printf("\t\t\t\t\t    Enter valid Mobile No: ");
        }
        scanf("%[^\n]", &mobNo);
        bool check = checkNumber(mobNo);
        if (check) {
            break;
        }
    }
    fflush(stdin); fflush(stdout);

    AVL_Node* curr = getNode(root, mobNo);
    if (curr == NULL) {
        printf("\n\t\t\t\tERROR: No Customer found corresponding to number %s", mobNo);
        printf("\n\t\t\t\t          PLEASE REGISTER FIRST!");
        printf("\n\t\t\t\t  ============================================================ \n");
        return;
    }

    printf("\n\t\t\t\t   ~~ HELLO \"%s\"! PLEASE ENTER YOUR SHOPPING DETAILS.! ~~\n\n", curr->cust.firstName);

    int amount;
    char productDesc[30];
    char date[25];
    
    fflush(stdin);
    printf("\t\t\t\t\t    Price of Product (in INR)    : ");
    scanf("%d", &amount);
    fflush(stdin);
    printf("\t\t\t\t\t    Product Description          : ");
    scanf("%[^\n]", &productDesc);
    formatName(productDesc);
    fflush(stdin);

    printf("\n\t\t\t\t\t    Press 1 to PAY, 0 to ADD Due-> \n\n");
    first = true;
    char ch = '-';
    while(1){
        if(first){
            printf("\t\t\t\t\t      Enter Choice: ");
            first = false;
        }else{
            printf("\t\t\t\t\t      Enter Valid Choice: ");
        }
        fflush(stdout);
        scanf("%c", &ch);
        fflush(stdin);
        if(ch == '1' || ch == '0'){
            break;
        }
    }
    bool paid = false;
    if (ch == '1') {
        paid = true;
    } else {
        if (curr->cust.dueAmount == -1) {
            curr->cust.dueAmount = amount;
        } else {
            curr->cust.dueAmount += amount;
        }
    }
    pushInStack(&curr->cust.stack, amount, productDesc, paid);

    printf("\n\n\t\t\t\t               *** ALL TRANSACTIONS HISTORY ***\n\n");
    displayStack(curr->cust.stack);
    printf("\n\t\t\t\t               ===============================\n\n");

    if(curr->cust.dueAmount != 0){
        if(curr->cust.dueAmount >= 2500){
            printf("\t\t\t\t\tWARNING: TOO MUCH DUE\n");
        }
        printf("\n\t\t\t\t\tYOUR TOTAL DUE AMOUNT IS: %d\n", curr->cust.dueAmount);

        printf("\n\t\t\t\t\t    Press 1 to PAY WHOLE DUE, OR ANY KEY TO CANCEL OPERATION-> \n\n");
        printf("\t\t\t\t\t\t   Enter Choice: ");
        scanf("%c", &ch);
        fflush(stdin);
        if (ch == '1') {
            payDue(curr->cust);
            curr->cust.dueAmount = 0;
            printf("\n\t\t\t\t                 ~~ DUE PAID SUCCESSFULLY~~\n\n");
        } else {
            printf("\n\t\t\t\t                    ~~ DUE STILL UNPAID ~~\n\n");
        }
    } else {
            printf("\n\t\t\t\t                 ~~ NO DUE AMOUNT PENDING ~~\n\n");
    }
    
    printf("\n\t\t\t\t  ============================================================ \n");
}

// ================== FILE HANDLING FUNCTIONS ==================

// ------------------ EXTRACTING ------------------

void extractingDatabase() {
    FILE* filePointer;
    char dataToBeRead[500];
    int totalCustomers = 0;
    dataToBeRead[0] = '\0';
    
    filePointer = fopen("Database.txt", "r");

    if (filePointer == NULL) {
        printf("\n\t\t\tDATABASE ERROR WHILE EXTRACTING\n");
        return;
    }
    printf("CHECKING DATABASE...\n");
    int i = 0;

    // printf("Part 1\n");
    while (fgets(dataToBeRead, 500, filePointer) != NULL) {
        i++;
        if(i == 4){
            trimSpaces(dataToBeRead);
            int run = 0;
            while(dataToBeRead[run] != ':'){
                run++;
            }
            run += 2;
            char customer[10]; int mark = 0;
            while(dataToBeRead[run] != '\0'){
                customer[mark++] = dataToBeRead[run++];
            }
            customer[mark] = '\0';
            totalCustomers = stringToInt(customer);
            break;
        }
    }
    if(i < 4){
        printf("DATABASE IS NOT CREATED YET\n");
        return;
    }

    if(totalCustomers == 0){
        printf("DATABASE IS EMPTY, NO PREVIOUS RECORDS FOUND\n");
        return;
    }

    printf("RETRIVING DATABASE...\n");
    i = 0;
    // printf("Part 2\n");
    while (fgets(dataToBeRead, 500, filePointer) != NULL && i < 2) {
        i++;
    }

    // printf("Part 3\n");
    char firstName[25];
    char lastName[25];
    char mobNo[15];
    char address[25];
    char date[15];
    char dueAmountStr[15];
    int dueAmount;

    for(i = 0; i < totalCustomers; i++){
        if(fgets(dataToBeRead, 500, filePointer) != NULL){
            trimSpaces(dataToBeRead);
            if(dataToBeRead[1] == '-'){
                printf("Broken\n");
                break;
            }
            
            int ptr = 2;
            getSubstring(firstName, dataToBeRead, ptr, ptr+20-1);
            trimSpaces(firstName);
            ptr = ptr+20-1;
            ptr += 4;
            
            getSubstring(lastName, dataToBeRead, ptr, ptr+20-1);
            trimSpaces(lastName);
            ptr = ptr+20-1;
            ptr += 4;

            getSubstring(mobNo, dataToBeRead, ptr, ptr+12-1);
            trimSpaces(mobNo);
            ptr = ptr+12-1;
            ptr += 4;

            getSubstring(address, dataToBeRead, ptr, ptr+20-1);
            trimSpaces(address);
            ptr = ptr+20-1;
            ptr += 4;

            getSubstring(date, dataToBeRead, ptr, ptr+13-1);
            trimSpaces(date);
            ptr = ptr+13-1;
            ptr += 4;

            getSubstring(dueAmountStr, dataToBeRead, ptr, ptr+11-1);
            trimSpaces(dueAmountStr);
            if(dueAmountStr[0] == 'N'){
                dueAmount = 0;
            }else{
                dueAmount = stringToInt(dueAmountStr);
            }

            // if (dueAmount == 0) {
            //     printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", firstName, lastName, mobNo, address, date, "NIL");
            // } else {
            //     printf("      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", firstName, lastName, mobNo, address, date, dueAmount);
            // }

            Customer newCust;

            strcpy(newCust.firstName, firstName);
            strcpy(newCust.lastName, lastName);
            strcpy(newCust.mobNo, mobNo);
            strcpy(newCust.adress, address);
            strcpy(newCust.registeredDate, date);
            newCust.dueAmount = dueAmount;
            newCust.stack = NULL;
            
            root = insertAVL(root, newCust);
            // printf("\nreturned after insertion\n");
            
            // displayAllCustomers();
            fflush(stdout);
        }
    }

    printf("ALL %d CUSTOMERS DATA IS SUCCESSFULLY RETRIVED FROM DATABASE", totalCustomers);
    fclose(filePointer);
}

// ------------------ EXTRACTING OVER ------------------

// ------------------ INSERTING ------------------

void fileShowCust(Customer cust, FILE* fptr) {
    char date[25];
    char temp[300];
    if (cust.dueAmount == 0) {
        sprintf(temp, "      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", cust.firstName, cust.lastName, cust.mobNo, cust.adress, cust.registeredDate, "NIL");
    } else {
        sprintf(temp, "      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11d |\n", cust.firstName, cust.lastName, cust.mobNo, cust.adress, cust.registeredDate, cust.dueAmount);
    }
    // printf("%s\n", temp);
    fputs(temp, fptr);
}

void filePrintInInorderFashion(AVL_Node* root, FILE* fptr) {
    if (root == NULL) {
        return;
    }
    filePrintInInorderFashion(root->left, fptr);
    fileShowCust(root->cust, fptr);
    filePrintInInorderFashion(root->right, fptr);
}

void renewDatabase() {
    FILE* fptr = NULL;
    fptr = fopen("Database.txt", "w");

    if (fptr == NULL) {
        printf("\n\t\t\tDATABASE ERROR WHILE RENEWING\n");
        return;
    }

    char temp[200];
    fputs("\n\t\t\t\t\t\t\t\t  ******************* REGISTERED CUSTOMERS *******************\n\n", fptr);
    if (root == NULL) {
        sprintf(temp, "     TOTAL CUSTOMERS: %d\n", nodesInAvl);
        fputs(temp, fptr);
        fputs("\n\t\t\t\t\t\t\t\t      ------------------ DATABASE EMPTY ------------------\n\n", fptr);
    } else {
        sprintf(temp, "     TOTAL CUSTOMERS: %d\n", nodesInAvl);
        fputs(temp, fptr);
        sprintf(temp, "      |-----------------------------------------------------------------------------------------------------------------|\n");
        fputs(temp, fptr);
        sprintf(temp, "      | %-20s | %-20s | %-12s | %-20s | %-13s | %-11s |\n", "FIRST NAME", "LAST NAME", "MOB NO.", "ADDRESS", "REG DATE", "DUE AMOUNT");
        fputs(temp, fptr);
        sprintf(temp, "      |-----------------------------------------------------------------------------------------------------------------|\n");
        fputs(temp, fptr);
        filePrintInInorderFashion(root, fptr);
        sprintf(temp, "      |-----------------------------------------------------------------------------------------------------------------|\n");
        fputs(temp, fptr);
    }
    fputs("\n\t\t\t\t\t\t\t\t  ============================================================ \n", fptr);
    fclose(fptr);
}
// ------------------ INSERTING OVER ------------------

// ================== FILE HANDLING FUNCTIONS OVER ==================

void menu() {
    printf("\n\n\t\t\t\t*************************** MENU *************************** \n");
    printf("\n\t\t\t\t\t1. Register Customer");
    printf("\n\t\t\t\t\t2. Delete Customer");
    printf("\n\t\t\t\t\t3. Update Customer");
    printf("\n\t\t\t\t\t4. Buy Product");
    printf("\n\t\t\t\t\t5. Display all");
    printf("\n\t\t\t\t\t6. Exit");
    printf("\n\n\t\t\t\t============================================================ \n");
}

int main() {

    // ERROR
    extractingDatabase();

    menu();
    int input;
    bool stop = false;
    while (1) {
        printf("\n\t\tENTER CHOICE: ");
        scanf("%d", &input);

        switch (input) {
        case 1:
            // Done
            // Tested
            registerCustomer(root);
            break;
        case 2:
            // Done
            // Tested
            updateCustomer();
            break;
        case 3:
            // Done
            // Tested
            deleteCustomer();
            break;
        case 4:
            buyProduct();
            break;
        case 5:
            // Done
            // Tested
            displayAllCustomers();
            break;
        case 6:
            stop = true;
            renewDatabase();
            printf("\n\t\tQuitting..");
            break;
        default:
            printf("\n\t\t*Enter proper value*\n");
            break;
        }

        if (stop) {
            break;
        }
    }

    return 0;
}