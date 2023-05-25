// Link : https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Time Complexity : O(n)
// Approach-> Last se sbka dist and first se sbka dist and ab dono m max ko return

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxDistance(vector<int> &colors)
{
    // Constraints are very small we can try 2 possible combination
    //  2nd could be generalised approach jha harr approach try krrhe
    //  Max dist start ya end se hoga to ek baar start k harr combination and ek baar end ka
    int i = 0;
    int j = colors.size() - 1;
    int ans = 0;
    // dekho ek baaar aage se aaoge and saare colors k liye dekhlo
    while (i < j)
    {
        if (colors[i] != colors[j])
        {
            ans = max(ans, abs(i - j));
        }
        i++;
    }
    // phir ek baar peeche se move krenge
    i = 0;
    j = colors.size() - 1;
    int ans2 = 0;
    while (i < j)
    {
        if (colors[i] != colors[j])
        {
            ans2 = max(ans2, abs(j - i));
        }
        j--;
    }
    return max(ans, ans2);
}

int main()
{

    return 0;
}