/*Coding Problem
Problem Statement : All indexes of x
Problem Level : MEDIUM
Problem Description :
Given an array of length Nand an integer x, you need to find all the indexes where x is present in the input array.Save all the indexes in an array(in increasing order).
Do this recursively.Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e.size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
indexes where x is present in the array(separated by space)

Constraints :
    1 <= N <= 10 ^ 3

    Sample Input :
5
9 8 10 8 8
8

Sample Output :
1 3 4 */

#include<iostream>
using namespace std;

void firstIndex(int a[], int n, int key, int b[]) {
    //issue is that we have to write this code without sorting the array
    //Since its an array we will divide it into n-1 and 1 for recursion
    //total kitna values h wo b[0] me store krrhe h to kuch return krne k jrurt nhi
    //Base case
    if (n <= 0)
    {
        return;
    }

    //calculation step
    if (a[n - 1] == key)
    {
        //will return the index of the element in that array - n-1 issliye kuuki array me index (0 to n-1) rehta h.
        //So wahan recursion me jitna baar array divide hua uska size se n-1 will be last element original index
        b[b[0]] = n - 1;
        cout << b[b[0]];
        b[0] += 1;
        cout << b[0] << endl;
        //yhan return type dalenge to issee case pr hi tut jayega and return bas ek hi value hoga but hume multiple values dene h
    }
    //Induction step -  harr baar jab ye array break horha h seze 1 se ghata jaarha h- so jitna baar tutega size will decrease
    firstIndex(a, n - 1, key, b);
}

int main() {
    int a[5] = { 7,12,34,22,34 };
    int b[5];
    b[0] = 1;
    firstIndex(a, 5, 34, b);
    cout << "Total Index found is " << b[0] << endl;
    for (int i = 1; i < b[0]; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    return 0;
}

