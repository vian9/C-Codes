#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int dequeue[MAX];
int rear1 = -1, front1 = -1, rear2 = MAX, front2 = MAX;

void enQueue(int x) {
    if (rear1 == -1 && front1 == -1) {
        dequeue[++rear1] = x;
        front1++;
    }
    else if (rear2 == rear1 + 1) {
        printf("QUEUE IS FULL!!! NOT POSSIBLE!!!\n");
    }
    else {
        dequeue[++rear1] = x;
    }
}

int deQueue() {
    if (rear1 == -1) {
        printf("QUEUE IS EMPTY!!! DELETION NOT POSSIBLE\n");
        return -1;
    }
    else if (rear1 == front1) {
        int val = front1;
        rear1 = front1 = -1;
        return dequeue[val];
    }
    else {
        int val = front1;
        front1++;
        return dequeue[val];
    }
}

void Display1() {
    if (rear1 == -1 && front1 == -1) {
        printf("THIS QUEUE IS EMPTY!!!CAN'T PRINT ANYTHING\n");
    }
    else {
        printf("FIRST QUEUE:  ");
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", dequeue[i]);
        }
        printf("\n");
    }
}

void Inject(int x) {
    if (rear2 == MAX && front2 == MAX) {
        dequeue[--rear2] = x;
        front2--;
    }
    else if (rear2 == rear1 + 1) {
        printf("QUEUE IS FULL !!! NOT POSSIBLE!!!\n");
    }
    else {
        dequeue[--rear2] = x;
    }
}

int Eject() {
    if (rear2 == MAX && front2 == MAX) {
        printf("QUEUE IS EMPTY!!! DELETION NOT POSSIBLE\n");
        return -1;

    }
    else if (rear2 == front2) {
        int val = front2;
        rear2 = front2 = MAX;
        return dequeue[val];
    }
    else {
        int val = front2;
        front2--;
        return dequeue[val];
    }
}

void Display2() {
    if (rear2 == MAX && front2 == MAX) {
        printf("THIS QUEUE IS EMPTY!!!CAN'T PRINT ANYTHING\n");
    }
    else {
        printf("SECOND QUEUE:  ");
        for (int i = front2; i >= rear2; i--) {
            printf("%d ", dequeue[i]);
        }
        printf("\n");
    }
}

void menu() {
    printf("\n Please Select the Option from the Menu: \n");
    printf("\n1. To Enqueue");
    printf("\n2. To Dequeue");
    printf("\n3. To Display queue 1");
    printf("\n4. To Inject");
    printf("\n5. To Eject");
    printf("\n6. To Display queue 2");
    printf("\n7. To Menu");
    printf("\n8. To EXIT\n\n");
}

int main() {
    int num, x;
    menu();

    int val;
    int input;
    while (1) {
        printf("\nEnter your option you choose from the Menu: ");

        scanf("%d", &num);
        switch (num) {
        case 1:
            printf("\nEnter the number of values to Insert: ");
            scanf("%d", &x);
            printf("Enter %d values: ", x);
            for(int i = 0; i < x; i++){
                scanf("%d", &input);
                enQueue(input);
            }
            break;
        case 2:
            val = deQueue();
            if (val != -1) {
                printf("\nThe number deleted is: %d\n", val);
            }
            break;
        case 3:
            Display1();
            break;
        case 4:
            printf("\nEnter the number of values to Insert: ");
            scanf("%d", &x);
            printf("Enter %d values: ", x);
            for(int i = 0; i < x; i++){
                scanf("%d", &input);
                Inject(input);
            }
            break;
        case 5:
            val = Eject();
            if (val != -1) {
                printf("\nThe number deleted is: %d\n", val);
            }
            break;
        case 6:
            Display2();
            break;
        case 7:
            menu();
            break;
        case 8:
            exit(0);
        }
    }
}