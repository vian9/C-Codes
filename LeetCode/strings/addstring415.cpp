#include <iostream>
#include <vector>
using namespace std;

string addStrings(string num1, string num2)
{
    int m = num1.length();
    int n = num2.length();
    vector<int> sum;
    int i = m - 1, j = n - 1;
    int carry = 0;
    while (i > -1 && j > -1)
    {
        int a = num1[i] - '0';
        int b = num2[j] - '0';
        if (a + b + carry > 9)
        {
            int num = (a + b + carry) - 10;
            carry = 1;
            sum.push_back(num);
            i--;
            j--;
        }
        else
        {
            int num = (a + b + carry);
            carry = 0;
            sum.push_back(num);
            i--;
            j--;
        }
    }

    while (i > -1)
    {
        int a = num1[i] - '0';
        if (a + carry > 9)
        {
            int num = (a + carry) - 10;
            carry = 1;
            sum.push_back(num);
            i--;
        }
        else
        {
            int num = (a + carry);
            carry = 0;
            sum.push_back(num);
            i--;
        }
    }

    while (j > -1)
    {
        int b = num2[j] - '0';
        if (b + carry > 9)
        {
            int num = (b + carry) - 10;
            carry = 1;
            sum.push_back(num);
            j--;
        }
        else
        {
            int num = (b + carry);
            carry = 0;
            sum.push_back(num);
            j--;
        }
    }
    if (carry != 0)
    {
        sum.push_back(carry);
    }

    m = sum.size();
    j = m - 1;
    string finsum;

    for (int l = 0; l < m; l++)
    {
        cout << sum[j] << endl;
        finsum += (sum[j] + '0');
        j--;
    }
    return finsum;
}

int main()
{
    string sre = addStrings("401716832807512840963", "167141802233061013023557397451289113296441069");
    cout << sre << endl;
    return 0;
}