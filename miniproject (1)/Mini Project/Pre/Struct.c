#include <stdbool.h>
#include <stdio.h>

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