#include<iostream>
#include "Node.cpp"
using namespace std;

Node* deleteNode(Node* head, int i) {
    int count = 0; //Array k jaisa count lenge
    Node* temp = head;
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next; //Jaise hi LL k length se jada i hoga to temp me NULl aa jayega temp->next se and ye while loop rukk jayega
        count++;
    }

    //Now we are on Node before the position where we have to place
    if (temp != NULL)
    {
        Node* a = temp->next;   //Jisse delete krna h;
        Node* b = a->next; //Delete k agla wala node
        temp->next = b;
        delete a;
    }

    if (i == 0)
    {
        Node* a = head;
        head = head->next;
        delete a;
        return head;
    }
    return head;
}

Node* insertNode(Node* head, int i, int data) {
    Node* newNode = new Node(data);
    int count = 0; //Array k jaisa count lenge
    Node* temp = head;
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next; //Jaise hi LL k length se jada i hoga to temp me NULl aa jayega temp->next se and ye while loop rukk jayega
        count++;
    }

    //Now we are on Node before the position where we have to place
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    return head;
}


//Better Take input function with better time complexity
Node* takeInputBetter() {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        Node* newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
            //or tail = newNode;
        }
        cin >> data;
    }

    return head;
}

//Take Input for LL
Node* takeInput() {
    Node* head = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        Node* newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                //was getting Segmentation fault here bcoz (temp->next == NULL) ye likh dia tha nd arrow jisse access krrha wo NULL ko point krega to error dega
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }

    return head;
}


//Print LL
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    // Node n1(10);
    // Node n2(20);
    // Node* n3 = new Node(30);
    // Node* n4 = new Node(40);
    // Node* head = &n1;
    // n1.next = &n2;
    // n2.next = n3;
    // n3->next = n4;
    // cout << n1.next;
    // cout << endl;
    // print(head);
    cout << endl;
    Node* head1 = takeInput();
    print(head1);
    Node* head2 = takeInputBetter();
    print(head2);
    cout << endl;
    int i;
    int data;
    cin >> i >> data;
    insertNode(head2, i, data);
    print(head2);
    cout << endl;
    int j;
    cin >> j;
    deleteNode(head2, j);
    print(head2);
    cout << endl;
    return 0;
}