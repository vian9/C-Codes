// Link : https://leetcode.com/problems/fruit-into-baskets/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int totalFruit(vector<int> &fruits)
{
    int ans = 0;
    int last = 0;
    // Hum ek jgh se start krenge nd move on krte jayenge jbtk koi dusra na mile
    vector<int> mp(2, -1);
    int f1 = 0;
    int f2 = 0;
    for (int i = 0; i < fruits.size(); i++)
    {
        if (mp[0] == fruits[i] || mp[1] == fruits[i])
        {
            last += 1;
        }
        else
        {
            if (mp[0] == -1)
            {
                f1 = i;
                mp[0] = fruits[i];
            }
            else if (mp[1] == -1)
            {
                f2 = i;
                mp[0] = fruits[i];
            }
            else
            {
                if (mp[0] != fruits[i])
                {
                    f1 = i;
                    i = f2 - 1;
                    last = 0;
                }
                else
                {
                    f2 = i;
                    i = f1 - 1;
                    last = 0;
                }
            }
        }
        ans = max(ans, last);
    }

    return ans;
}

int main()
{

    return 0;
}