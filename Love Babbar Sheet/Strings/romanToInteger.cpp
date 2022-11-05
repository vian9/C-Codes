// Link : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
// Time Complexity : O(n)
// Approach-> Check all condition related to roman numeral and especially exception
// Second approach is take a map and put all Roman and corresponding values....and now iterate string from right
// For map approach : Agar i k left mein i se chota value wala ho toh usse i se subtract krdo like XL....L is 50 and X is 10 XL = 50 - 10

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Solution 1 : here I am checking all conditions
int romanToDecimal(string &str)
{
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] == 'I' || str[i] == 'X' || str[i] == 'C') && i != str.length() - 1)
        {
            if ((str[i] == 'I' && str[i + 1] == 'V') || (str[i] == 'I' && str[i + 1] == 'X'))
            {
                if (str[i + 1] == 'V')
                {
                    num += 4;
                    i++;
                    continue;
                }
                else
                {
                    num += 9;
                    i++;
                    continue;
                }
            }
            if ((str[i] == 'X' && str[i + 1] == 'L') || (str[i] == 'X' && str[i + 1] == 'C'))
            {
                if (str[i + 1] == 'L')
                {
                    num += 40;
                    i++;
                    continue;
                }
                else
                {
                    num += 90;
                    i++;
                    continue;
                }
            }
            if ((str[i] == 'C' && str[i + 1] == 'D') || (str[i] == 'C' && str[i + 1] == 'M'))
            {
                if (str[i + 1] == 'D')
                {
                    num += 400;
                    i++;
                    continue;
                }
                else
                {
                    num += 900;
                    i++;
                    continue;
                }
            }
        }
        if (str[i] == 'I')
        {
            num += 1;
        }
        if (str[i] == 'V')
        {
            num += 5;
        }
        if (str[i] == 'X')
        {
            num += 10;
        }
        if (str[i] == 'L')
        {
            num += 50;
        }
        if (str[i] == 'C')
        {
            num += 100;
        }
        if (str[i] == 'D')
        {
            num += 500;
        }
        if (str[i] == 'M')
        {
            num += 1000;
        }
    }
    return num;
}

int main()
{

    return 0;
}