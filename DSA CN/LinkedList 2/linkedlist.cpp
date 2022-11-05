#include<iostream>
#include "Node.cpp"
using namespace std;

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

Node* midLL(Node* head) {
    //return hum slow wala krenge jo mid pr hoga
    if (head == NULL)
    {
        //If LL is empty to head NULL return ho jayega
        return head;
    } else if (head->next == NULL)
    {
        //If LL has only one element just return that element
        return head;
    } else
    {
        //Jab Null ya Single LL nhi h to isme aayega ab slow and fast m nodes ko point krwa dias
        Node* slow = head;
        Node* fast = head->next;
        //AND(&&) Condition lgega OR(||) nhi lgega kuuki Dono me se koi bhi ek condition fulfill nhi hua to loop se bahar aana chahiye
        //wrna (fast->next != NULL) satisfy nhi krrha Even Number of nodes me but (fast !=NULL) satisy horha to loop m andar chal jayega and segmentation fault.
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

        }
        return slow;
    }
}

//Print LL
void print(Node* head) {
    Node* temp = head;
    if (temp == NULL)
    {
        //Jab LL is empty tb display krega
        cout << "LL is empty";
    }

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
    Node* head = takeInputBetter();
    print(head);
    cout << endl;
    Node* mid = midLL(head);
    if (mid != NULL)
    {   //Condition check krlia agar NULL LL hai to return value null hoga to uske aage pointer lagane se error de deta segmentation fault.
        cout << mid->data;
    }

    cout << endl;
    return 0;
}