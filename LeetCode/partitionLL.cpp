#include <iostream>
#include "Node.cpp"
using namespace std;

// Partition LL Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1, 2, 2, 4, 3, 5]
Node *partitionLLOriginal(Node *head, int x)
{
    Node *beforeList = NULL;
    Node *afterList = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data >= x)
        {
            if (afterList == NULL)
            {
                afterList = temp;
                tail2 = temp;
            }
            else
            {
                tail2->next = temp;
                tail2 = temp;
            }
            temp = temp->next;
        }
        else
        {
            if (beforeList == NULL)
            {
                beforeList = temp;
                tail1 = temp;
            }
            else
            {
                tail1->next = temp;
                tail1 = temp;
            }
            temp = temp->next;
        }
    }
    if (beforeList != NULL)
    {
        head = beforeList;
        tail1->next = afterList;
        if (afterList != NULL)
        {
            tail2->next = NULL;
        }
    }

    return head;
}

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Node *sumOfLL(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head = NULL;
    Node *tail = NULL;
    while (temp1 != NULL)
    {
        Node *n1 = new Node(temp1->data);
        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            tail = n1;
        }
        temp1 = temp1->next;
    }

    tail = head;
    int ans = 0;
    while (temp2 != NULL && tail->next != NULL)
    {
        tail->data += temp2->data;
        if (tail->data >= 10)
        {
            ans = tail->data;
            tail->data = (ans % 10);
            ans = ans / 10;
            if (tail->next != NULL)
            {
                tail->next->data += ans;
                ans = 0;
            }
        }

        tail = tail->next;
        temp2 = temp2->next;
    }

    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            Node *n1 = new Node(temp2->data);
            if (ans > 0)
            {
                n1->data += ans;
            }
            tail->next = n1;
            temp2 = temp2->next;
            tail = n1;
            if (tail->data > 9)
            {
                ans = tail->data;
                tail->data = (ans % 10);
                ans = ans / 10;
            }
        }
    }
    if (tail != NULL)
    {
        while (tail->next != NULL)
        {
            if (ans > 0)
            {
                tail->data += ans;
            }

            if (tail->data > 9)
            {
                ans = tail->data;
                tail->data = (ans % 10);
                ans = ans / 10;
            }
            if (tail->next != NULL)
            {
                tail->next->data += ans;
                ans = 0;
            }
            tail = tail->next;
        }
    }

    if (tail->next == NULL)
    {
        if (tail->data > 9)
        {
            ans = tail->data;
            tail->data = (ans % 10);
            ans = ans / 10;
        }
    }

    if (ans > 0)
    {
        Node *n1 = new Node(ans);
        tail->next = n1;
        tail = n1;
    }

    return head;
}

// Better Take input function with better time complexity
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
    cout << endl;
    Node *head = takeInputBetter();
    print(head);
    cout << endl;
    // int x;
    // cin >> x;
    // Node *head2 = partitionLLOriginal(head, x);
    // print(head2);
    Node *head2 = takeInputBetter();
    print(head2);
    cout << endl;
    Node *head3 = sumOfLL(head, head2);
    print(head3);
    cout << endl;
    return 0;
}