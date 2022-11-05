/* Coding Problem
Problem Statement : Quick Sort
Problem Level : MEDIUM
Problem Description :
Sort an array A using Quick Sort.
Change in the input array itself.So no need to return or print anything.
<br>
Input format :
Line 1 : Integer n i.e.Array size
Line 2 : Array elements(separated by space)

Output format :
Array elements in increasing order(separated by space)

Constraints :
    1 <= n <= 10 ^ 3

    Sample Input 1 :
    6
    2 6 8 5 4 3

    Sample Output 1 :
    2 3 4 5 6 8

    Sample Input 2 :
    5
    1 5 2 7 3

    Sample Output 2 :
    1 2 3 5 7 */

#include<iostream>
using namespace std;

int smallCount(int a[], int pivot, int low, int high) {
    //Total kitna smaller ya equal hai wo ans return krega
    int ans = 0;
    //MISTAKE: starts with low+1 and till high+1(numbers ko krke dekho tb sahi lgega)
    //i= low+1 as low par pivot hai and 0 nhi kuuki phir jab arrays part me tutega to jruri nhi low ka index 0 se hi start ho
    for (int i = low + 1; i <= high; i++)
    {
        if (pivot >= a[i])
        {
            ans = ans + 1;
        }
    }
    // cout << ans << endl;
    return ans;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    //pivot position nikal kr wahan pr daal denge pivot ko
    int pivotPos = low + smallCount(a, pivot, low, high);
    a[low] = a[pivotPos];
    a[pivotPos] = pivot;

    //i low se and j high se jabtk condition fullfill krrha h
    int i = low, j = high;
    while (i<pivotPos && j>pivotPos)
    {
        if (a[j] > pivot)
        {
            //right wala already bada hai to j leftward move krega
            j--;
        } else if (a[i] < pivot)
        {
            //left wala already chota hai to rightward move krega
            i++;
        } else
        {
            //jab left bada and right chota to swap ho jayega
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    return pivotPos;
}

void quickSort(int a[], int low, int high) {
    //Base Case
    if (low >= high)
    {
        return;
    }

    //Partition ka index return krega
    int c = partition(a, low, high);

    //induction step
    quickSort(a, low, c - 1);
    quickSort(a, c + 1, high);
}

int main() {
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
    quickSort(a, 0, n - 1);
    cout << "Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}