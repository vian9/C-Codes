#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct SLL_Node {
    struct SLL_Node* next;
    int Amount;
    char productDescription[30];
    bool paid;
    char date[25];
} typedef SLL_Node;

struct Customer{
    char firstName[15];
    char lastName[15];
    char adress[100];
    char mobNo[14];
    int dueAmount;
    char registeredDate[25];
    SLL_Node* stack;
} typedef Customer;

struct AVL_Node {
    Customer cust;
    struct AVL_Node* left;
    struct AVL_Node* right;
    int heightOfAvl;
} typedef AVL_Node;

// ============ To get time ============
char* getDate(char* date){
    time_t now;
    time(&now);
    strcpy(date, ctime(&now));
}

void extractDate(char* date){
    char onlyDate[13];
    int i = 0;
    //  Sat Nov 27 20:10:21 2021
    int mark = 4;
    for(int r = 0; r < 7; r++){
        onlyDate[i++] = date[mark++];
    }
    mark = 20;
    for(int r = 0; r < 4; r++){
        onlyDate[i++] = date[mark++];
    }
    onlyDate[i] = '\0';
    // printf("\n in extract: %s\n", onlyDate);
    strcpy(date, onlyDate);
}
// ========== To get time Over ==========

// =========== String Formatters ===========
char toUpper(char ch){
    if(ch >= 'a' && ch <= 'z'){
        ch = ch-32;
    }
    return ch;
}

char toLower(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        ch = ch+32;
    }
    return ch;
}

// tested
void spaceFormat(char* str){
    int len = strlen(str);
    
    char formattedString[100];
    
    int j = 0;
    int i = 0;
    
    while(1){
        while(str[i] != '\0' && str[i] == ' '){
            i++;
        }
        while(str[i] != '\0' && str[i] != ' '){
            formattedString[j++]  = str[i++];
        }
        if(str[i] == '\0'){
            break;
        }
        formattedString[j++] = ' ';
    }

    if(formattedString[j-1] == ' '){
        formattedString[j-1] = '\0';
    }else{
        formattedString[j] = '\0';
    }

    strcpy(str, formattedString);
}

// tested
void formatName(char* firstName){

    spaceFormat(firstName);

    int len = strlen(firstName);
    if(len == 0){
        return;
    }

    firstName[0] = toUpper(firstName[0]);
    for(int i = 1; i < len; i++){
        if(firstName[i-1] == ' '){
            firstName[i] = toUpper(firstName[i]);
        }else{
            firstName[i] = toLower(firstName[i]);
        }
    }
}

void trimSpaces(char* str){
    char trimmed[500];
    int st = 0, end = strlen(str) - 1;

    while(str[st] != '\0' && (str[st] == ' ' || str[st] == '\t')){
        st++;
    }

    while(end >= 0 && (str[end] == ' ' || str[end] == '\t')){
        end--;
    }

    if(st > end){
        trimmed[0] = '\0';
    }else{
        int j = 0;
        for(int i = st; i <= end; i++){
            trimmed[j++] = str[i];
        }
        trimmed[j] = '\0';
    }
    strcpy(str, trimmed);
}

void formatNumber(char* mobNo){
    char formatted[15];
    int i = 0, j = 0;
    while(mobNo[j] != '\0'){
        if(mobNo[j] != ' '){
            formatted[i++] = mobNo[j];
        }
        j++;
    }
    formatted[i] = '\0';
    strcpy(mobNo, formatted);
}

bool checkNumber(char* mobNo){
    formatNumber(mobNo);
    int i = 0;
    while(mobNo[i] != '\0'){
        if(!(mobNo[i] >= '0' && mobNo[i] <= '9')){
            printf("\n\t\t\t\t     ERROR: Mob No. can only contain digits! Try again!\n\n");
            return false;
        }
        i++;
    }

    int len = strlen(mobNo);
    if(len == 10){
        return true;
    }else if(len < 10){
        printf("\n\t\t\t\t     ERROR: Mob No. seems SHORT! Try again!\n\n");
    } else {
        printf("\n\t\t\t\t     ERROR: Mob No. seems LONG! Try again!\n\n");
    }
    fflush(stdout);
    return false;
}

int stringCompare(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 > len2){
        return 1;
    }else if(len1 < len2){
        return -1;
    }else{
        for(int i = 0; i < len1; i++){
            if(str1[i] < str2[i]){
                return -1;
            }else if(str1[i] > str2[i]){
                return 1;
            }
        }
    }
    return 0;
}

void getSubstring(char* ans, char* str, int start, int end){
    if(start > end || strlen(str)-1 < end){
        ans[0] = '\0';
        printf("\nGet string error from function getString\n");
        return;
    }

    int run = 0;
    for(int i = start; i <= end; i++){
        ans[run++] = str[i]; 
    }
    ans[run] = '\0';
}

void stringCopy(char* str1, char* str2){
    int i = 0;
    while(str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

int stringToInt(char* str){
    int ans = 0;
    sscanf (str, "%d", &ans);
    return ans; 
}
// =========== String Formatters Over ===========

// int main(){
//     // for testing

//     // char str[] = "         my baby i love your voice             ";
//     // printf("~%s~\n", str);
//     // trim(str);
//     // printf("~%s~\n", str);
//     // char date[50];
//     // getDate(date);
//     // printf("%s", date);

//     char str[] = "| Para                 | Sir                  | 7040911715   | Pune                 | Nov 30 2021   | NIL         |";
//     char temp[21];
//     getSubstring(temp, str, 2, 21);
//     printf("%s\n", temp);

//     return 0;
// }

int nodesInAvl = 0;

AVL_Node* newAVLNode(Customer cust) {
    nodesInAvl++;
    AVL_Node* new_node = (AVL_Node*) malloc(sizeof(AVL_Node));
    if(new_node == NULL){
        printf("\n\t\t **MEMORY EXHAUSTED can't perform further operations!**\n\n");
        return NULL;
    }
    new_node->cust = cust;
    new_node->left = new_node->right = NULL;
    new_node->heightOfAvl = 1;
    return new_node;
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int heightOfAvl(AVL_Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->heightOfAvl;
}

int getBalanceFactor(AVL_Node* root) {
    if (root == NULL) {
        return 0;
    }
    return heightOfAvl(root->left) - heightOfAvl(root->right);
}

AVL_Node* leftRotate(AVL_Node* root) {
    AVL_Node* newMid = root->right;
    AVL_Node* temp = newMid->left;

    // rotation
    newMid->left = root;
    root->right = temp;

    // updating heightOfAvl
    root->heightOfAvl = max(heightOfAvl(root->left), heightOfAvl(root->right)) + 1;
    newMid->heightOfAvl = max(heightOfAvl(newMid->left), heightOfAvl(newMid->right)) + 1;

    // return new root after rotation
    return newMid;
}

AVL_Node* rightRotate(AVL_Node* root) {
    AVL_Node* newMid = root->left;
    AVL_Node* temp = newMid->right;

    // rotation
    newMid->right = root;
    root->left = temp;

    // updating heightOfAvl
    root->heightOfAvl = max(heightOfAvl(root->left), heightOfAvl(root->right)) + 1;
    newMid->heightOfAvl = max(heightOfAvl(newMid->left), heightOfAvl(newMid->right)) + 1;

    // return new root after rotation
    return newMid;
}

AVL_Node* insertAVL(AVL_Node* root, Customer cust) {

    // 1. Normal BST insertAVL
    if (root == NULL) {
        // printf("\n=========inserted===========\n");
        root = newAVLNode(cust);
    } else if (stringCompare(cust.mobNo, root->cust.mobNo) < 0) {
        root->left = insertAVL(root->left, cust);
    } else if (stringCompare( cust.mobNo,root->cust.mobNo) > 0) {
        root->right = insertAVL(root->right, cust);
    } else {
        return root;
    }

    // 2. Updata heightOfAvl of ancestor nodes
    root->heightOfAvl = 1 + max(heightOfAvl(root->left), heightOfAvl(root->right));

    // 3. Get the balance factor of the ancestor
    int balance = getBalanceFactor(root);

    // if balanced then simply return
    if (balance <= 1 && balance >= -1) {
        return root;
    }
    // printf("\n Unbalanced at %s\n", cust.mobNo);

    // if current AVL_Node is unbalanced, then
    // check for 4 cases

    // Left Left case
    // if (balance > 1 && cust.mobNo < root->left->cust.mobNo) {
    if (balance > 1 && stringCompare(cust.mobNo, root->left->cust.mobNo) < 0) {
        // printf("case1");
        return rightRotate(root);
    }

    // Right Right case
    // if (balance < -1 && cust.mobNo > root->right->cust.mobNo) {
    if (balance < -1 && stringCompare(cust.mobNo, root->right->cust.mobNo) > 0) {
        // printf("case2");
        return leftRotate(root);
    }

    // Left Right case
    // if (balance > 1 && cust.mobNo > root->left->cust.mobNo) {
    if (balance > 1 && stringCompare(cust.mobNo, root->left->cust.mobNo) > 0) {
        // printf("case3");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left case
    // if (balance < -1 && cust.mobNo < root->right->cust.mobNo) {
    if (balance < -1 && stringCompare(cust.mobNo, root->right->cust.mobNo) < 0) {
        // printf("case4");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVL_Node* inorderSucc(AVL_Node* root) {
    AVL_Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

AVL_Node* deleteAVL(AVL_Node* root, char* mobNo) {
    // Normal BST deletion
    if (root == NULL) {
        return NULL;
    }

    if (stringCompare(mobNo, root->cust.mobNo) < 0) {
        root->left = deleteAVL(root->left, mobNo);
    } else if (stringCompare(mobNo, root->cust.mobNo) > 0) {
        root->right = deleteAVL(root->right, mobNo);
    } else {
        // AVL_Node has no child
        if (root->left == NULL && root->right == NULL) {
            AVL_Node* toDel = root;
            free(toDel);
            nodesInAvl--;
            // printf("deleted");
            return NULL;
        }

        // AVL_Node with only one child or no child
        else if (root->left == NULL) {
            struct AVL_Node* temp = root->right;
            free(root);
            nodesInAvl--;
            // printf("deleted");
            return temp;
        } else if (root->right == NULL) {
            struct AVL_Node* temp = root->left;
            free(root);
            // printf("deleted");
            nodesInAvl--;
            return temp;
        }

        // AVL_Node with two children: Get the inorder successor
        // (smallest in the right subtree)
        AVL_Node* temp = inorderSucc(root->right);

        // Copy the inorder successor's content to this AVL_Node
        root->cust = temp->cust;

        // Delete the inorder successor
        root->right = deleteAVL(root->right, temp->cust.mobNo);
    }

    if (root == NULL) {
        return root;
    }

    // 2. Update heightOfAvl of ancestor AVL_Node
    root->heightOfAvl = max(heightOfAvl(root->left), heightOfAvl(root->right)) + 1;

    // 3. Get the balance factor of the ancestor
    int balance = getBalanceFactor(root);

    // if balanced then simply return
    if (balance <= 1 && balance >= -1) {
        return root;
    }

    // if current AVL_Node is unbalanced, then
    // check for 4 cases

    // Left Left case
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}

AVL_Node* getNode(AVL_Node* root, char mobNo[]){
    if(root == NULL){
        return NULL;
    }

    if(stringCompare(mobNo, root->cust.mobNo) == 0){
        return root;
    }else if(stringCompare(mobNo, root->cust.mobNo) < 0){
        return getNode(root->left, mobNo);
    }else if(stringCompare(mobNo, root->cust.mobNo) > 0){
        return getNode(root->right, mobNo);
    }
}

// void levelOrderTraversal(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     queue<AVL_Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty()) {
//         AVL_Node* curr = q.front();
//         q.pop();

//         if (curr) {
//             cout << curr->data << " ";
//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//         } else if (!q.empty()) {
//             q.push(NULL);
//             cout << endl;
//         }
//     }
// }

// void inorder(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }
//     inorder(root->left);
//     printf("%s ", root->cust.mobNo);
//     inorder(root->right);
// }

// void preorder(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }
//     printf("%s ", root->cust.mobNo);
//     fflush(stdout);
//     preorder(root->left);
//     preorder(root->right);
// }

// void postorder(AVL_Node* root) {
//     if (root == NULL) {
//         return;
//     }
//     postorder(root->left);
//     postorder(root->right);
//     printf("%s ", root->cust.mobNo);
//     fflush(stdout);
// }

// int main() {
//     AVL_Node* root = NULL;

//     // int arr[] = { 14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20 };
//     // int n = sizeof(arr) / sizeof(arr[0]);

//     char str1[] = "1111111111";
//     char str2[] = "2222222222";
//     char str3[] = "8766964749";
//     char str4[] = "8380927810";
//     char str5[] = "7654567325"; 

//     Customer cust1;
//     strcpy(cust1.mobNo, str1);
//     Customer cust2;
//     strcpy(cust2.mobNo, str2);
//     Customer cust3;
//     strcpy(cust3.mobNo, str3);
//     Customer cust4;
//     strcpy(cust4.mobNo, str4);
//     Customer cust5;
//     strcpy(cust5.mobNo, str5);
//     root = insertAVL(root, cust1);
//     root = insertAVL(root, cust2);
//     root = insertAVL(root, cust3);
//     root = insertAVL(root, cust4);
//     root = insertAVL(root, cust5);

//     printf("here\n\n");
//     inorder(root);
//     printf("\n\n");

//     printf("here\n\n");
//     postorder(root);
//     printf("\n\n");
//     return 0;
// }

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