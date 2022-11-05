#include <iostream>
using namespace std;

bool checkString(string str2, int j)
{
    int k = j;
    for (int i = 0; i < j; i++)
    {
        if (str2[i] != str2[k])
        {
            k++;
            return false;
            break;
        }
        k++;
    }
    return true;
}

int checkPal(string str2, int i)
{
    int n = str2.length();
    bool flag = true;
    for (int j = i; j < n; j++)
    {
        if (str2[j] == str2[0])
        {
            flag = checkString(str2, j);
            if (flag)
            {
                i = j - 1;
                break;
            }
        }
    }
    return i;
}

bool compStr(string str, string pal)
{
    int m = str.length();
    int n = pal.length();
    bool comp = true;
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        k = k % n;
        if (str[i] != pal[k])
        {
            k++;
            return false;
            break;
        }
        k++;
    }
    return true;
}

bool compCheck(string str1, string str2, string pal)
{
    bool same = true;
    same = compStr(str2, pal);
    bool same2 = true;
    same2 = compStr(str1, pal);
    if (same == true && same2 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string gcdOfStrings(string str1, string str2)
{
    int i = 1;
    int m = str1.length();
    int n = str2.length();
    bool small = true;
    bool flag = true;
    i = checkPal(str2, i);
    string pal;
    for (int j = 0; j < i + 1; i++)
    {
        pal += str2[j];
    }
    if (compCheck(str1, str2, pal))
    {
        return pal;
    }
    else
    {
        return "";
    }
}

int main()
{

    return 0;
}