#include <stdio.h>

void swap(int arry[], int i, int j){
    int temp = arry[i];
    arry[i] = arry[j];
    arry[j] = temp;
}

int partition(int arry[], int l, int r){
    int pivot = arry[r];
    int i = l-1;

    for(int j = l; j < r; j++){
        if(arry[j] < pivot){
            i++;
            swap(arry, i, j);
        }
    }
    swap(arry, i+1, r);
    return i+1;
}

void quickSort(int arry[], int l, int r){
    if(l < r){
        int pi = partition(arry, l, r);
        quickSort(arry, l, pi-1);
        quickSort(arry, pi+1, r);
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

    quickSort(arry, 0, x-1);

    printf("\nSorted array using QUICK SORT: ");

    printf("\n");
    for(int i = 0; i < x; i++){
        printf("%d ", arry[i]);
    }printf("\n\n");
    
    return 0;
}