#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int subString(string *s1, int size, string *s2)
{
    int n = s1->size();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            (s2)[k] = (*s1).substr(i, j);
            k++;
            cout << s1->substr(i, j) << "h";
            cout << (*s2)[k] << "a";
            cout << s2[k] << "hi" << endl;
        }
    }

    return k;
}

string *xoring(string *a, string *b, int j)
{
    string *ans;
    int x = (*a).size();
    int y = (*b).size();
    string *a1;
    string *b1;
    if (x != y)
    {
        if (x > y)
        {
            string *s3;
            for (int i = 0; i < (x - y); i++)
            {
                (*s3).insert(0, "0", 1);
            }
            // cout << s3 << endl;
            *b1 = *s3 + (*b)[j];
            *a1 = *a;
            delete s3;
            // cout << a1 << endl;
            // cout << b1 << endl;
        }
        else
        {
            string *s4;
            for (int i = 0; i < (y - x); i++)
            {
                (*s4).insert(0, "0", 1);
            }

            *a1 = *s4 + *a;
            *b1 = (*b)[j];
            delete s4;
            // cout << s4 << endl;
            // cout << a1 << endl;
            // cout << b1 << endl;
        }
    }

    int n = (x > y) ? x : y;
    // Loop to iterate over the
    // Binary Strings
    for (int i = 0; i < n; i++)
    {
        // If the Character matches
        if ((*a1)[i] == (*b1)[i])
            *ans += "0";
        else
            *ans += "1";
    }
    return ans;
}

int binaryToDecimal(string *s)
{
    int value = 0;
    int indexCounter = 0;
    for (int i = (*s).size() - 1; i >= 0; i--)
    {

        if ((*s)[i] == '1')
        {
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    return value;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int len;
        string *s1 = new string;
        cin >> len;
        int size = fact(len);
        string *s2 = new string[size];
        cin >> *s1;
        int a = subString(s1, size, s2);
        string *s3;
        *s3 = s2[0];
        for (int j = 1; j < a; j++)
        {
            (s3) = xoring(s3, s2, j);
        }
        delete s1;
        delete[] s2;
        int val = binaryToDecimal(s3);
        delete s3;
        cout << val << endl;
    }

    return 0;
}