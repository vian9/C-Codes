/*Coding Problem
Problem Statement: Sum of array (recursive)
Problem Level: EASY
Problem Description:
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
Sum

Constraints :
1 <= N <= 10^3

Sample Input 1 :
3
9 8 9

Sample Output 1 :
26

Sample Input 2 :
3
4 2 1

Sample Output 2 :
7 */

#include<iostream>
using namespace std;
//glt
int sumOfArrays(int a[], int low , int high){
    //Base case
    if (low == high)
    {
        cout<< a[low];
        return a[low];
    }
    int mid = (low+high)/2;
    return sumOfArrays(a, 0, mid);  
}
//sahi
int sumArrays(int a[], int n){
    //Base - isme jab array zero ho jaye
    if (n<=0)
    {
        return 0;
    } 
    //array ko ek ek element me torr do aur uska last element add krte jao
    return sumArrays(a, n-1) + a[n-1];
}

int main() {
int a[10]= {9,8,2,3,4,1,7,3,5,3};

int sum = sumOfArrays(a , 0, 9);
cout<<sum<<endl;
cout<<sumArrays(a, 10);

return 0;
}

