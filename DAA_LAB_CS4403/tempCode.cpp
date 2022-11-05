#include<iostream>
using namespace std;

struct Pair{
	int min;
	int max;
};

struct Pair min_Max(int a[], int i , int j){
	struct Pair minMax;	
	if (i == j){
		minMax.max = a[i];
		minMax.min = a[j];	
		return minMax;
	}else if (i == j-1){
        if (a[j]>a[i]){
            minMax.max = a[j];
            minMax.min = a[i];
        }
        else{
            minMax.max = a[i];
            minMax.min = a[j];
        }
        
    } else{
        int mid = (i+j)/2;
        struct Pair left = min_Max(a, i , mid);
        struct Pair right = min_Max(a, mid+1, j);
        if(left.min < right.min){
            minMax.min = left.min;
        }else{
            minMax.min = right.min;
        }
        if(left.max < right.max){
            minMax.max = right.max;
        }else{
            minMax.max = left.max;
        }
    }

return minMax;
}

int main(){
	int a[8]={91,83,73,27,37,18,191,88};
    int n = sizeof(a);
	struct Pair minMax = min_Max(a, 0 ,7);
	cout<<endl;
	cout << "Minimum is "<< minMax.min << endl;
	cout << "Maximum is "<< minMax.max;
	cout<<endl;	
    cout<<endl;	
	return 0;
}
