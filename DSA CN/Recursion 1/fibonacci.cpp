#include<iostream>
using namespace std;

int fib(int n){
    //Base Case - 2 Base cases for n = 0 and 1
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    //Induction Step - n k liye krenge
    int fibLarge = fib(n-1)+fib(n-2);
    return fibLarge;
}

int main() {
int n;
cin>>n;
cout<<fib(n)<<endl;

return 0;
}