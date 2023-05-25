// Link : https://leetcode.com/problems/assign-cookies/
// Time Complexity : O(nlogn)
// Approach-> Phle sort krdo and then uska s ko iterate krdo jbtk equal size na aa jaye

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int k = 0;
    int i = 0;
    // Cookie pr iterate kro kuuki wo chota ho skta h s....toh s ko iterate kro
    while (i < s.size())
    {
        if (k < g.size() && g[k] <= s[i])
        {
            k++;
            count++;
        }
        i++;
    }

    return count;
}

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;
    int j = 0;
    // Cookies pr iterate kro kuuki wo chota ho skta h move krte jayenge
    for (int i = 0; i < s.size(); i++)
    {
        // Agar kbhi cookie bada hogya to sorted h ab break krdo usse bada hi aayega ab
        if (j >= g.size())
        {
            break;
        }
        if (g[j] <= s[i])
        {
            count++;
            j++;
        }
    }
    return count;
}

int main()
{

    return 0;
}