#include<iostream>
using namespace std;

int fact(int n){
    //Base Case
    if (n==0){
        return 1;
    }
    //Induction Step
    return n*fact(n-1);
}

int main() {
int n;
cin>>n;
cout<<fact(n)<<endl;

return 0;
}