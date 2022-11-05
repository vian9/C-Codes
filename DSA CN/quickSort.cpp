#include <iostream>
using namespace std;

int partition(int x[], int i, int j)
{
    int left = i, right = j - 1, pivot = j, complete = 0, t;
    while (!complete)
    {
        while (x[left] <= x[pivot] && pivot != left)
            left++;
        if (pivot != left)
        {
            t = x[pivot];
            x[pivot] = x[left];
            x[left] = t;
            pivot = left;
        } else
            complete = 1;
        if (!complete)
        {
            while (x[right] >= x[pivot] && pivot != right)
                right--;
            if (pivot != right)
            {
                t = x[pivot];
                x[pivot] = x[right];
                x[right] = t;
                pivot = right;
            } else
                complete = 1;
        }
    }
    return pivot;
}

void quicksort(int x[], int i, int j)
{
    int pivot;
    if (i < j)
    {
        pivot = partition(x, i, j);
        quicksort(x, i, pivot - 1);
        quicksort(x, pivot + 1, j);
    }
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
    quicksort(a, 0, n - 1);
    cout << "Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}