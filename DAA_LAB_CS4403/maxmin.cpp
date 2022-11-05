#include <iostream>
using namespace std;

struct minMax(int a[], int i, int j){
    int min = a[i];
    int max = a[j];
    if(i==j){
        min = a[i];
        max = a[j];
    }else if (i = j-1)
    {
        if (a[j]>a[i])
        {
            max = a[j];
            min = a[i];
        }
        else{
            max = a[i];
            min = a[j];
        }
        
    } else{
        int mid = (i+j)/2;
        int left = minMax(a, i , mid-1);
        int right = minMax(a, mid, j);
        if(left.min < right.min){
            minMax.min = left.min;
            cout<<min;
        }else{
            minMax.min = right.min;
            cout<<min;
        }
        if(left.max < right.max){
            minMax.max = left.max;
            cout<<max;
        }else{
            minMax.max = right.max;
            cout<<max;
        }
    }
}

int main() {
    int a[10]={9,12,38,42,55,61,73,83,91,98};
    int n = sizeof(a);
    minMax(a, 0, 9);
    return 0;
}