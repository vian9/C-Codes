#include<iostream>
using namespace std;

inline bool resultPrint(int res){
    // cant write this line in return type int but without return use void or with return use datatype bool for either true cout this.
    return (res==-1)?cout<<"Number not found":cout<<"Number found at index "<<res<<endl;
}

int binarySearch(int a[], int key, int high, int low){
int mid = (high+low)/2;
    //Base Case
    if (high<low){
        return -1;
    }
    //Base case if code running
    if (a[mid]==key){
        return mid;
    }
    //Induction Step - since int return type u have to return values that will get returned to main after recursion
    else if (key > a[mid]){
        // dont write only binarySearch(a, key, high, mid+1); as it wont return then values to main after receiving back from recurison
        return binarySearch(a, key, high, mid+1);
    } else {
        return binarySearch(a, key, mid-1, low);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    int result = 0;
    result = binarySearch(a, key, n-1, 0);
    resultPrint(result);
    

return 0;
}       