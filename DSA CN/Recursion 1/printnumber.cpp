/*Coding Problem
Problem Statement: Print numbers
Problem Level: EASY
Problem Description:
Given is the code to print numbers from 1 to n in increasing order recursively. But it contains few bugs that you need to rectify such that all the test cases pass.
Input Format :
Integer n

Output Format :
Numbers from 1 to n (separated by space)

Constraints :
1 <= n <= 10000

Sample Input 1 :
 6

Sample Output 1 :
1 2 3 4 5 6

Sample Input 2 :
 4

Sample Output 2 :
1 2 3 4 */

#include<iostream>
using namespace std;

void printNumbers(int n) {
    //Base Case 
    if (n == 0)
    {
        cout << "";
        //return dena jruri h wrna wo rukega nhi recursive call pr value wapas nhi jayega and code chlta hi rhega
        return;
    }
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    //Induction Step
    printNumbers(n - 1);
    //Jav value return hokr wapas aayega to ye run hoga
    if (n > 1) {
        cout << n << " ";
    }
}

void printNumbers2(int n) {
    //Base Case 
    if (n == 0)
    {
        cout << "";
        //return dena jruri h wrna wo rukega nhi recursive call pr value wapas nhi jayega and code chlta hi rhega
        return;
    }
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    //Jav value return hone se phle ye run hoga to opposite m number print krega
    if (n > 1) {
        cout << n << " ";
    }
    //Induction Step
    printNumbers2(n - 1);
}

int main() {
    int n;
    cin >> n;
    printNumbers(n);
    cout << endl;
    printNumbers2(n);
    return 0;
}