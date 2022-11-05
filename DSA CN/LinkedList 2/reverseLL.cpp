#include<iostream>
#include "Node.cpp"
using namespace std;

//Reverse LL iterativve se 
Node* reverseLLIterative(Node* head) {
    //3 pointer lelia of type node- prev current and nextt
    Node* current = head;
    Node* prev = NULL;
    Node* nextt = current->next;
    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = nextt;

        if (nextt != NULL) //ye condition issliye kuuki jab Nextt NUll par chal jayega to uspr arrow operator will give error
        {
            nextt = nextt->next;
        }
    }
    return prev;
}

//Direct recursion se and loop travel krke reverse kia - Time Complexity - O(n^2)
Node* reverseLLRecursive1(Node* head) {
    //Base case- LL has 1 or 0 elements
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    //PMI Induction step - ye reverse krke lakr de dega - trust him
    Node* smallLL = reverseLLRecursive1(head->next);

    //PMI Hypothesis step 
    Node* temp = smallLL;
    while (temp->next != NULL)
    {
        //last node chahiye issliye temp->next != NULL kia h
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    //return krdia new head jisse pura LL travel kr ske
    return smallLL;
}

//Instead of tranversing we will maintain Tail pointer and isse time complexity-O(kn) ho jayega 
//Iske liye hume head and tail dono return krna hoga and usse sahi se values bhi rkhna hoga in recursion taki call m lost na ho jaye
//-uske liye ek class bna lenge

class Pair {
public:
    Node* head;
    Node* tail;
};

Pair reverseLLRecursive2(Node* head) {
    //Base case- LL has 1 or 0 elements
    if (head == NULL || head->next == NULL)
    {
        Pair pairLL;
        pairLL.head = head;
        pairLL.tail = head;
        return pairLL;
    }

    //PMI Induction step - ye reverse krke lakr de dega - trust him
    Pair smallPairLL = reverseLLRecursive2(head->next);

    //PMI Hypothesis step
    smallPairLL.tail->next = head;
    head->next = NULL;
    smallPairLL.tail = head; //Tail bhi update krdia last Node se
    //return krdia pair jisse pura LL travel kr ske as head and tail dono hai dono ko update krdiye ki aage recursive call me use ho.
    return smallPairLL;
}

Node* reverseLLTail(Node* head) {
    return reverseLLRecursive2(head).head;
}

//Best Approach - No need of extra class or pointer tail - time complexity - O(n)
Node* reverseLLBest(Node* head) {
    //Base case- LL has 1 or 0 elements
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    //PMI Induction step - ye reverse krke lakr de dega - trust him
    Node* smallLL = reverseLLRecursive1(head->next);

    //PMI Hypothesis step - Since jo last Node hai uska address still head-> next me saved h to directly usko use krenge
    head->next->next = head;
    //Node* tail = head->next;
    //tail->next = head; ye dono step ko upar 1 hi step m krdia
    head->next = NULL;

    //return krdia new head jisse pura LL travel kr ske
    return smallLL;
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
    cout << endl;
    Node* head = takeInputBetter();
    print(head);
    cout << endl;
    Node* reverseHead1 = reverseLLRecursive1(head);
    print(reverseHead1);
    cout << endl;
    Node* reverseHead2 = reverseLLTail(reverseHead1);
    print(reverseHead2);
    cout << endl;
    Node* reverseHead3 = reverseLLBest(reverseHead2);
    print(reverseHead3);
    cout << endl;
    Node* reverseHead4 = reverseLLIterative(reverseHead3);
    print(reverseHead4);
    cout << endl;
    return 0;
}