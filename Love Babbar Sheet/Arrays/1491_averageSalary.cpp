// Link : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// Time Complexity : O(n)
// Approach-> Just sum lete jao last m max and min minus krke average krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double average(vector<int> &salary)
{
    double sum = 0;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < salary.size(); i++)
    {
        sum += salary[i];
        maxi = max(salary[i], maxi);
        mini = min(mini, salary[i]);
    }
    sum -= (maxi + mini);
    return sum / (salary.size() - 2);
}

int main()
{

    return 0;
}