#include <stdio.h>

void merge(int* arry, int low, int mid, int high){
    int l1 = mid-low+1;
    int l2 = high-mid;

    int a[l1], b[l2];

    for(int i = 0; i < l1; i++){
        a[i] = arry[low+i];
    }
    for(int i = 0; i < l2; i++){
        b[i] = arry[mid+1+i];
    }

    int i = 0, j = 0, k = low;

    while(i < l1 && j < l2){
        if(a[i] <= b[j]){
            arry[k] = a[i];
            i++; 
        }else{
            arry[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < l1){
        arry[k] = a[i];
        i++; k++;
    }

    while(j < l2){
        arry[k] = b[j];
        j++; k++;
    }
}

void mergeSort(int* arry, int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;

        mergeSort(arry, low, mid);
        mergeSort(arry, mid+1, high);

        merge(arry, low, mid, high);
    }
}

int main(){
    printf("\n\nEnter the size of array: ");
    int x; scanf("%d", &x);
    printf("\nEnter %d elements: ", x);
    int arry[x];
    for(int i = 0; i < x; i++){
        scanf("%d", &arry[i]);
    }

    mergeSort(arry, 0, x-1);

    printf("\nSorted array using MERGE SORT: ");

    printf("\n");
    for(int i = 0; i < x; i++){
        printf("%d ", arry[i]);
    }printf("\n\n");
    
    return 0;
}