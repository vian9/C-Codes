// Link : https://leetcode.com/problems/palindrome-number/description/
// Time Complexity : O(n)
// Approach-> Deque lia and usme back se dalta gya.....to front m last digit aayega usko nikalte gye and form the num
// if nums are same then true

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalindrome(int x)
{
    long long MOD = 10e9 + 7;
    deque<int> num;
    if (x < 0)
        return false;
    int val = x;
    while (val > 0)
    {
        int dig = val % 10;
        num.push_back(dig);
        val = val / 10;
    }
    long long vali = 0;
    while (!num.empty())
    {
        int dig = num.front();
        num.pop_front();
        vali *= 10;
        vali += dig;
    }
    if (x == vali)
        return true;
    return false;
}

int main()
{

    return 0;
}