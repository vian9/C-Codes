/* Coding Problem
Problem Statement : Last index of x
Problem Level : MEDIUM
Problem Description :
Given an array of length Nand an integer x, you need to findand return the last index of integer x present in the array.Return - 1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from(N - 1).
Do this recursively.Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e.size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
last index or -1

Constraints :
    1 <= N <= 10 ^ 3

    Sample Input :
4
9 8 10 8
8

Sample Output :
3 */

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
    else if (a[n - 1] == key)
    {
        //will return the index of the element in that array - n-1 issliye kuuki array me index (0 to n-1) rehta h.
        //So wahan recursion me jitna baar array divide hua peeche se hota rha but jaise hi element milgya uske liye n-1 return krdia kuuki wo original array ka index hi h
        return n - 1;

    } else if (firstIndex(a, n - 1, key) == -1)
    {
        //Yeh issliye kuuki agar element end tak nhi mila to ye arraySize-1 return krrha tha iske bina issliye ye check laga dia taki agar element na mile to direct -1 return
        return -1;
    } else
    {
        //Induction step - yhan add(+1) nhi h issliye taki harr baar jab ye array break horha h to n-1 ka size chota horha h to jab bhi milega wo chota array size ka n-1 return krega jo ki original index hi h
        return firstIndex(a, n - 1, key);
    }


}

int main() {

    int a[5] = { 7,12,8, 10, 8 };
    int res = firstIndex(a, 5, 7);
    cout << "Last Index is " << res << endl;
    return 0;
}