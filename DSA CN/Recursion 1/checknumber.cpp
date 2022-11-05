/*Coding Problem
Problem Statement : Check number recursively
Problem Level : EASY
Problem Description :
Given an array of length N and an integer x, you need to find if x is present in the array or not.Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e.size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
'true' or 'false'

Constraints :
    1 <= N <= 10 ^ 3

    Sample Input 1 :
    3
    9 8 10
    8

    Sample Output 1 :
    true

    Sample Input 2 :
    3
    9 8 10
    2

    Sample Output 2 :
    false */

#include<iostream>
using namespace std;

int binarySearch(int a[], int low, int high, int key) {
    int mid = (high + low) / 2;
    //Base Case
    if (high > low)
    {
        return -1;
    }


    if (a[mid] == key)
    {
        return mid;
    } //Divide and conquer
    else if (a[mid] > key)
    {
        return binarySearch(a, low, mid - 1, key);
    } else {
        return binarySearch(a, mid + 1, high, key);
    }
}

int main() {

    //apply Binary search for sorted array to find its index too
    int a[5] = { 7,12,18,22,34 };
    int res = binarySearch(a, 0, 4, 4);
    cout << res << endl;
    return 0;
}
