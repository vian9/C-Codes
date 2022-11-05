// Link : https://leetcode.com/problems/integer-to-roman/submissions/
// Link : https://practice.geeksforgeeks.org/problems/convert-to-roman-no/1
// Time Complexity : O(n) but slow
// Approach-> I stored all the possible basic digits in map usme O(1) mein search and traverse krke find kia and string bnadia
// Gfg's approach is very simple but unique.....usne ek set bnadia and ab usse number ko phle 1000 se divide kia jo quotient h
// utna baar M repeat hoga...phir baaki k remainder aagye put forward krdia
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function to convert decimal to Roman Numerals - GfG's Solution
int printRoman(int number)
{
    int numbr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    string s = "";
    while (num > 0)
    {
        int div = num / numbr[i];
        num = num % numbr[i];
        while (div--)
        {
            s = s + sym[i];
        }
        i--;
    }
    return s;
}

// My LeetCode and GeeksForGeeks
string intToRoman(int num)
{
    unordered_map<int, string> value;
    value[1] = "I";
    value[2] = "II";
    value[3] = "III";
    value[4] = "IV";
    value[5] = "V";
    value[6] = "VI";
    value[7] = "VII";
    value[8] = "VIII";
    value[9] = "IX";
    value[10] = "X";
    value[20] = "XX";
    value[30] = "XXX";
    value[40] = "XL";
    value[50] = "L";
    value[60] = "LX";
    value[70] = "LXX";
    value[80] = "LXXX";
    value[90] = "XC";
    value[100] = "C";
    value[200] = "CC";
    value[300] = "CCC";
    value[400] = "CD";
    value[500] = "D";
    value[600] = "DC";
    value[700] = "DCC";
    value[800] = "DCCC";
    value[900] = "CM";
    value[1000] = "M";
    value[2000] = "MM";
    value[3000] = "MMM";

    int val = num;
    string s;
    int dig = 1;
    while (val > 0)
    {
        int last = val % 10;
        if (value.count(last * dig) > 0)
        {
            s = value.at(last * dig) + s;
        }
        dig = dig * 10;
        val = val / 10;
    }
    return s;
}

int main()
{

    return 0;
}