#include <bits/stdc++.h>
using namespace std;

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

vector<int> senderBits(int m, int k)
{
    vector<int> sender(m * k);
    cout << "Enter the bits from Sender" << endl;
    for (int i = 0; i < m * k; i++)
    {
        int a;
        cin >> a;
        sender[i] = a;
    }

    vector<int> sumSenderFirst = {sender.begin(), sender.begin() + m};
    vector<int> sumSenderSecond = {sender.begin() + m, sender.begin() + 2 * m};
    int last = 2 * m;
    for (int i = 1; i < k; i++)
    {
        sum2(sumSenderFirst, sumSenderSecond);
        sumSenderSecond = {sender.begin() + last, sender.begin() + last + m};
        last += m;
    }
    for (int i = 0; i < m; i++)
    {
        if (sumSenderFirst[i] == 1)
            sumSenderFirst[i] = 0;
        else
            sumSenderFirst[i] = 1;
    }
    cout << "Check Sum bits : ";
    for (int i = 0; i < m; i++)
    {
        cout << sumSenderFirst[i];
    }
    cout << endl;

    return sumSenderFirst;
}

bool receiverBits(int m, int k, vector<int> &reciever)
{
    vector<int> receiverr(m * k);
    cout << "Enter the bits from Receiver" << endl;
    for (int i = 0; i < m * k; i++)
    {
        int a;
        cin >> a;
        receiverr[i] = a;
    }

    vector<int> sumReceiverFirst = {receiverr.begin(), receiverr.begin() + m};
    vector<int> sumReceiverSecond = {receiverr.begin() + m, receiverr.begin() + 2 * m};
    int last = 2 * m;
    for (int i = 1; i < k; i++)
    {
        sum2(sumReceiverFirst, sumReceiverSecond);
        sumReceiverSecond = {receiverr.begin() + last, receiverr.begin() + last + m};
        last += m;
    }

    cout << "Receiver bits : ";
    for (int i = 0; i < m; i++)
    {
        cout << sumReceiverFirst[i];
    }
    cout << endl;
    sum2(sumReceiverFirst, reciever);
    for (int i = 0; i < m; i++)
    {
        // Sab ka sum will be 1 agar kahin bhi 0 hua to wrong data
        if (sumReceiverFirst[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m, k;
    cout << "Enter the Segment Length and No of Segments: " << endl;
    cin >> m >> k;
    vector<int> sender = senderBits(m, k);
    if (receiverBits(m, k, sender))
    {
        cout << "Data Accepted" << endl;
    }
    else
    {
        cout << "Data Rejected" << endl;
    }
    return 0;
}
// 10011001 11100010 00100100 10000100
// 10011001111000100010010010000100
// 1 0 0 1 1 0 0 1 1 1 1 0 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 0 0 1 0 0