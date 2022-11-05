/* Coding Problem
Problem Statement : First Index
Problem Level : EASY
Problem Description :
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array.Return - 1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively.Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e.size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
first index or -1

Constraints :
    1 <= N <= 10 ^ 3

    Sample Input :
4
9 8 10 8
8

Sample Output :
1 */

#include<iostream>
using namespace std;

int firstIndex(int a[], int n, int key) {
    //issue is that we have to write this code without sorting the array
    //Since its an array we will divide it into 1 and n-1 for recursion
    //Base case
    if (n <= 0)
    {
        return -1;
    }

    //calculation step
    else if (a[0] == key)
    {
        //will return the index of the element in that array - 0 issliye kuuki array me index (0 to n-1) rehta h.
        //So wahan recursion me jitna baar array divide hua +1 hota rha but jaise hi element milgya uske liye 0 add hua to get original index
        return 0;
    } else if (firstIndex(a + 1, n - 1, key) == -1)
    {
        //Yeh issliye kuuki agar element end tak nhi mila to ye arraySize-1 return krrha tha iske bina issliye ye check laga dia taki agar element na mile to direct -1 return
        return -1;
    } else
    {
        //Induction step - +1 issliye taki harr baar jab ye array break horha h index 1 se aage jaarha h- so jitna baar tutega index size will be utna time +1
        return firstIndex(a + 1, n - 1, key) + 1;
    }


}

int main() {

    int a[5] = { 7,12,12,22,34 };
    int res = firstIndex(a, 5, 34);
    cout << "First Index is " << res << endl;
    return 0;
}

