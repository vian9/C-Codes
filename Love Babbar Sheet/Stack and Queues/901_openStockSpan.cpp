// Link : https://leetcode.com/problems/online-stock-span/description/
// Time Complexity : O(n)
// Approach-> Similar as 1554.....phle span = 1 lo....aur stack m push kro price....agar price kaam h to span increase and pop

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

StockSpanner()
{
    stack<pair<int, int>> streak;
}

int next(int price)
{
    int span = 1;
    while (!streak.empty() && streak.top().second <= price)
    {
        span = span + streak.top().first;
        streak.pop();
    }
    streak.push({span, price});
    return span;
}

int main()
{

    return 0;
}