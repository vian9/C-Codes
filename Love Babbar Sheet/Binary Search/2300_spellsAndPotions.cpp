// Link : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Time Complexity : O(nlogn)
// Approach-> O(n2) : Agar saare spells ko saare potions se multiply krke check krlo but int overflow hoga
// Tb yeh kiya jaa skta h ki sort krdo potions ko and hum min value nikal le jisse bade wale values binary search se jo ho
// wo hmare successfull potions honge

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    vector<int> ans;
    sort(potions.begin(), potions.end());
    for (int i = 0; i < spells.size(); i++)
    {
        int val = spells[i];
        // formula to find ceil value of minimum needed
        long min = (success + val - 1) / val;
        cout << min;
        int ind = potions.size();
        ind = lower_bound(potions.begin(), potions.end(), min) - potions.begin();
        ans.push_back(potions.size() - ind);
    }
    cout << endl;
    return ans;
}

int main()
{

    return 0;
}