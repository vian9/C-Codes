#include <iostream>
using namespace std;

void mergeTwoSortedArray(int leftArray[], int rightArray[], int a[], int n, int m)
{
    int i = 0;
    int j = 0;
    int k = 0;


    while (i < n && j < m) {
        if (leftArray[i] <= rightArray[j]) {
            a[k] = leftArray[i];
            i++;
        } else {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        a[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < m) {
        a[k] = rightArray[j];
        j++;
        k++;
    }


}


void mergeSort(int a[], int size) {
    if (size == 0) {
        return;
    }
    if (size == 1)
    {
        return;
    }
    int n = size / 2;
    int m = size - n;

    int leftArray[n];
    int rightArray[m];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        leftArray[i] = a[k];
        k++;
    }

    for (int j = 0; j < m; j++)
    {
        rightArray[j] = a[k];
        k++;
    }
    mergeSort(leftArray, n);
    mergeSort(rightArray, m);

    mergeTwoSortedArray(leftArray, rightArray, a, n, m);
    return;
}

int main()
{
    cout << endl;
    int n;
    cout << "Enter the array size: ";
    cin >> n;
    int a[n];
    cout << "Enter the array to be sorted: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    mergeSort(a, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}