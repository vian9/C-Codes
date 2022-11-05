/*
Coding Problem
Problem Statement : Merge Sort
Problem Level : MEDIUM
Problem Description :
Sort an array A using Merge Sort.
Change in the input array itself.So no need to return or print anything.
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
    2 1 5 2 3

    Sample Output 2 :
    1 2 2 3 5 */

#include<iostream>
using namespace std;

void mergeArraysSorted(int a[], int low, int mid, int high) {
    int i = 0, j = mid + 1, k = 0;
    int b[high + 1];

    //Ek EK element ko compare krke b me daal rhe h and tbtk ye loop chlega jab tk dono me se koi ek part over na ho jaye
    while (i < mid + 1 && j < high + 1)
    {
        if (a[i] < a[j])
        {
            //agar mid se phle wala chota h to usko phle daal rhe and i++ krrhe
            b[k] = a[i];
            i++;
            k++;
        } else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    //jaise hi array ka koi ek part over hogya to i ya j me se jo bacha h wo baaki pura serial wise copy ho jayega as wo sorted hi h 
    //and compare wala to compare krke sort krdiye ye direct copy hokr de dega
    while (i < mid + 1)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j < high + 1)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int l = 0; l < high + 1; l++)
    {
        a[l] = b[l];
    }
}

void mergeSort(int a[], int low, int high) {
    //Base case
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    //Induction step- half m break krte gye jabtk bas 1 size ka array na bache
    mergeSort(a, 0, mid);
    mergeSort(a, mid + 1, high);
    //ab jab bas 1 size ka array bachrha usse merge krrhe sort krke and wo return hote jayega
    mergeArraysSorted(a, low, mid, high);

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

    mergeSort(a, 0, n - 1);

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