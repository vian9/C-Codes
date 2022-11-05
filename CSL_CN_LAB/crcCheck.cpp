// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sum2(vector<int> &a, vector<int> &b)
{
    int carry = 0;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        int sum = a[i] + b[i];
        sum += carry;
        carry = 0;
        if (sum == 2)
        {
            carry = 1;
            a[i] = 0;
        }
        else if (sum == 3)
        {
            carry = 1;
            a[i] = 1;
        }
        else if (sum < 2)
        {
            a[i] = sum;
        }
    }
    if (carry == 1)
    {
        vector<int> c;
        for (int i = 0; i < b.size() - 1; i++)
        {
            c.push_back(0);
        }
        c.push_back(1);
        sum2(a, c);
    }
}

vector<int> divisiveXor(vector<int> &a, vector<int> &key)
{
    int lastZero = 0;
    int n = key.size();
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (j < n)
        {
            a[i] = a[i] ^ key[j];
            j++;
            if (a[i] == 0 && lastZero == i - 1)
                lastZero = i;
            i++;
        }
        j = j % n;
        i = lastZero;
        cout << a[i];
    }
    cout << endl;
    vector<int> pos;
    for (int i = a.size() - n; i < a.size(); i++)
    {
        pos.push_back(a[i]);
    }
    return pos;
}

int main()
{
    int m, n;
    cout << "Enter the No of bits in Sender and key" << endl;
    cin >> m >> n;
    vector<int> sender(m);
    cout << "Enter the bits of sender: " << endl;
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        sender[i] = p;
    }
    vector<int> sender2 = sender;
    vector<int> key(n);
    cout << "Enter the bits of key" << endl;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        key[i] = p;
    }
    vector<int> rem = divisiveXor(sender, key);
    for (int i = 0; i < m; i++)
    {
        cout << sender[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << rem[i];
    }
    cout << endl;
    vector<int> posrem(m - n);
    for (int i = 0; i < n; i++)
    {
        posrem.push_back(rem[i]);
    }
    sum2(sender2, posrem);
    vector<int> recRem = divisiveXor(sender2, key);
    for (int i = 0; i < n; i++)
    {
        if (recRem[i] == 1)
        {
            cout << "Data Rejected" << endl;
            break;
        }
    }
    cout << "Data Accepted" << endl;
    return 0;
}