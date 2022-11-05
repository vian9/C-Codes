#include<iostream>
#include<algorithm>
using namespace std;

void knapsack(int a[], int b[], int c[], int w, int n) {
    float d[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = (float)b[i] / (float)c[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (d[i] < d[j])
            {
                swap(b[i], b[j]);
                swap(a[i], a[j]);
                swap(c[i], c[j]);
                swap(d[i], d[j]);
            }

        }

    }
    int left = w;
    float profit = 0;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
    }
    int currentWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + c[i] <= left)
        {
            ans[i] = a[i];
            profit += b[i];
            currentWeight += c[i];
            left -= c[i];
        } else
        {
            int weight = w - currentWeight;
            currentWeight += weight;
            profit += (d[i]) * weight;
            break;
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Profit " << profit << endl;

}

int main() {
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    int a[n];
    int b[n];
    int c[n];
    cout << "Enter the id , value and weight respectively: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << "Enter the knapsack capacity: " << endl;
    int w;
    cin >> w;
    knapsack(a, b, c, w, n);
    return 0;
}