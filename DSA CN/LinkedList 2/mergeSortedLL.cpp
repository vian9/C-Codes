#include<iostream>
#include "Node.cpp"
using namespace std;

// //Merge two LL such that final LL is sorted
//Hum yhan Node ko change krrhe h uske next k value ko to original LL m bhi change hoga.....head 1 and head 2 same Node ko point krega
//But dono heads k node ab mergeHead wale m aa jayega saare nodes k sth
Node* mergeLLSorted(Node* head1, Node* head2) {
    //jab dono me se koi ek LL Null ho, agar dono me ek bhi element hai to wo bhi compare krke return kr dega
    Node* h1 = head1;
    Node* h2 = head2;
    Node* finalHead = NULL;
    Node* finalTail = NULL;
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (h1->data > h2->data)
    {
        finalHead = h2;
        finalTail = h2;
        //Update nhi krenge to h2 phir se finalHead phir se whi node ko compare krke add krega 
        //but ye to ek obj h node with an specific address to 2 baar add kaise hoga to aage run nhi krega
        //indirectly mtlb yhi h isse hum aage jab phir se compare krte while loop m and finalTail m dalte to khud ko hi point krne bolte
        h2 = h2->next;
    } else
    {
        finalHead = h1;
        finalTail = h1;
        h1 = h1->next;
    }

    while (h1 != NULL && h2 != NULL)
        //dono condition satisfy krna chahiye-mtlb tb tk chlega jbtk koi ek LL exhaust na ho jaye
    {
        if (h1->data > h2->data)
        {
            finalTail->next = h2;
            finalTail = finalTail->next;
            h2 = h2->next;
        } else
        {
            finalTail->next = h1;
            finalTail = finalTail->next;
            h1 = h1->next;
        }
    }

    if (h1 != NULL)
    {
        //yhan while loop bhi laga kr kr skte thay but jrurt nhi tha wo bas time complexity badhata
        //since aage ka LL already connected hai to bas finalTail se head 1 ko jorr dia pura final LL aa jayega
        finalTail->next = h1;
    }

    if (h2 != NULL)
    {
        finalTail->next = h2;
    }

    return finalHead;
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
    Node* head1 = takeInputBetter();
    print(head1);
    cout << endl;
    cout << head1;
    cout << endl;
    Node* head2 = takeInputBetter();
    print(head2);
    cout << endl;
    Node* mergeHead = mergeLLSorted(head1, head2);
    print(mergeHead);
    cout << endl;
    //Hum yhan mergeLLSorted me Node ko change krrhe h uske next k value ko to original LL m bhi change hoga.....head 1 and head 2 same Node ko point krega
    //But dono heads k node ab mergeHead wale m aa jayega saare nodes k sth
    cout << head1->next->next->data;
    cout << head2->next->next->data;
    cout << endl;
    cout << head1;
    //AB dekhega ye nodes to ab merged LL se dekharhe h data .....so ab merged h kuuki 
    //but head1 me bas wo Node k address tha stored to wo uske pass abhi bhi point krrha but baaki saare uske bagal k nodes badal gye
    //kuuki next k value badal dia h
    cout << endl;
    return 0;
}