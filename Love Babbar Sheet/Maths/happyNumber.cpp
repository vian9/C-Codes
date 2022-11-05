// Link : https://leetcode.com/problems/happy-number/
// Time Complexity : O(10)
// Approach-> Agar 10 se jada baar recursive call hogya to return false.....ab just wo digits lena h n ka and uske digits k
// squares k sum lena h whi and agar kbhi bhi 1 hua to true

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isHappyorNot(int n, int count)
{
    if (n == 1)
    {
        return true;
    }
    if (count > 10)
    {
        return false;
    }

    vector<int> digits;
    while (n > 0)
    {
        int last = n % 10;
        n = n / 10;
        digits.push_back(last);
    }
    int newNum = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        newNum += (digits[i] * digits[i]);
    }
    return isHappyorNot(newNum, count + 1);
}

bool isHappy(int n)
{
    return isHappyorNot(n, 0)
}

int main()
{

    return 0;
}