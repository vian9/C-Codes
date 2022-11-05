// You are given two non - empty linked lists representing two non - negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero,
//  except the number 0 itself.

#include <iostream>
#include "Node.cpp"
using namespace std;

Node *addTwoLL(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head3 = NULL;
    Node *tail = NULL;
    int num = 0;
    int carry = 0;
    cout << "Head" << endl;
    while (temp1 != NULL && temp2 != NULL)
    {
        cout << "Head2" << endl;
        int num1 = temp1->data;
        int num2 = temp2->data;
        num += num1 + num2;
        if (num > 9)
        {
            carry = num - 10;
            num = 1;
        }
        else
        {
            carry = num;
            num = 0;
        }
        Node *newNode = new Node(carry);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        cout << "Head3" << endl;
        int num1 = temp1->data;
        num += num1;
        if (num > 9)
        {
            carry = num - 10;
            num = 1;
        }
        else
        {
            carry = num;
            num = 0;
        }
        Node *newNode = new Node(carry);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        cout << "Head4" << endl;
        int num1 = temp2->data;
        num += num1;
        if (num > 9)
        {
            carry = num - 10;
            num = 1;
        }
        else
        {
            carry = num;
            num = 0;
        }
        Node *newNode = new Node(carry);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        temp2 = temp2->next;
    }
    if (num != 0)
    {
        Node *newNode = new Node(num);
        if (head3 == NULL)
        {
            head3 = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head3;
}

Node *takeInputBetter()
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            // or tail = newNode;
        }
        cin >> data;
    }

    return head;
}

// Print LL
void print(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        // Jab LL is empty tb display krega
        cout << "LL is empty";
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head1 = takeInputBetter();
    Node *head2 = takeInputBetter();
    print(head1);
    cout << endl;
    print(head2);
    cout << endl;
    Node *head3 = addTwoLL(head1, head2);
    print(head3);
    return 0;
}
