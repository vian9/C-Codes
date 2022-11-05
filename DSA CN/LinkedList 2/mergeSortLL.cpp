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
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
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

Node* mergeSortLL(Node* head) {

    //Base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //PMI Induction Hypothesis
    //Mid nikal lia
    Node* mid = midLL(head);
    Node* midNext = mid->next;  //Mid k next ka LL ko break krdia dusra LL me
    mid->next = NULL;   //ab mid->next me NULL dalkr LL close
    //PMI Induction step - recursive calls
    Node* smallHead1 = mergeSortLL(head);
    Node* smallHead2 = mergeSortLL(midNext);
    return mergeLLSorted(smallHead1, smallHead2);
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
    // cout << endl;
    // cout << head1;
    // cout << endl;
    // Node* head2 = takeInputBetter();
    // print(head2);
    // cout << endl;
    // Node* mergeHead = mergeLLSorted(head1, head2);
    // print(mergeHead);
    cout << endl;
    //head 1 ka node khud kahan pr hoga pata nhi issliye head 1 to usse specific node ko still point krrha hoga but usse hume pura LL nhi milega
    Node* mergeSortHead = mergeSortLL(head1);
    print(mergeSortHead);
    cout << endl;
    // cout << head1;
    // cout << head1->next->next->data;
    // cout << head2->next->next->data;
    // cout << endl;
    // cout << midLL(head1)->data;
    return 0;
}