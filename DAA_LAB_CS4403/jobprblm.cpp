#include<iostream>
#include<algorithm>
using namespace std;

void jobSequenceGreedy(char a[], int b[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (c[j] < c[j + 1])
            {
                swap(c[j], c[j + 1]);
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
            }
        }
    }

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, b[i]) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << a[result[i]] << " ";
        }
    }
}

int main()
{
    cout << "Enter the number of Jobs: " << endl;
    int n;
    cin >> n;
    cout << "Enter the id, deadline and profit for each job respectively" << endl;
    char a[n];
    int b[n];
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    cout << "The maximum profit sequence of jobs is : ";

    jobSequenceGreedy(a, b, c, n);
    cout << endl;
    return 0;
}

