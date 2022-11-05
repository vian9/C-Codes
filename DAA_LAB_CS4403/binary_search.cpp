#include<iostream>
using namespace std;

int binarySearch(int a[], int key, int high, int low) {
    int mid = (high + low) / 2;
    if (high >= low) {
        if (a[mid] == key) {
            return mid;
        } else if (key > a[mid])
        {
            low = mid + 1;
            return binarySearch(a, key, high, mid + 1);
        } else {
            high = mid - 1;
            return binarySearch(a, key, mid - 1, low);
        }
    } else {
        return -1;
    }
}

int main() {
    int n;
    cout << endl;
    cout << "Enter array size: " << endl;
    cin >> n;
    int a[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cout << "Enter key: " << endl;
    cin >> key;
    int res = binarySearch(a, key, 6, 0);
    cout << endl;
    if (res == -1) {
        cout << "Key not found";
    } else {
        cout << "Key Found at index " << res << endl;
    }
    cout << endl;
    return 0;
}