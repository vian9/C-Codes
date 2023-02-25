// Link : https://leetcode.com/problems/find-the-town-judge/
// Time Complexity : O(n)
// Approach-> Bs instead of going for connections....just add krte jao kispr yeh add krrha nd kitna bar add krrha

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findJudge(int n, vector<vector<int>> &trust)
{
    // Savko hash m daal do
    // town judge trusts nobody and everybody except town judge trusts him
    vector<int> trusted(n + 1, 0);
    vector<int> trusting(n + 1, 0);
    for (int i = 0; i < trust.size(); i++)
    {
        // trusting is kispr wo trust krrha usme add kro
        trusting[trust[i][1]]++;
        // trusted is yeh kitna baar trust krrha kisipr
        trusted[trust[i][0]]++;
    }
    int val = -1;
    for (int i = 1; i < n + 1; i++)
    {
        // kisi aur pr trust nhi & isspr sbka trust
        if (trusted[i] == 0 && trusting[i] == n - 1)
        {
            val = i;
        }
    }
    return val;
}

int main()
{

    return 0;
}