// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void reverseStr(string &str)
{
    int len = str.length();
    int n = len - 1;
    int i = 0;
    while (i <= n)
    {
        // Using the swap method to switch values at each index
        swap(str[i], str[n]);
        n = n - 1;
        i = i + 1;
    }
}

int maximumNumberOfStringPairs(vector<string> &words)
{
    unordered_map<string, int> mp;
    for (int i = 0; i < words.size(); i++)
    {
        string new = words[i];
        string rev = reverseStr(new);
        mp[rev] = i;
    }

    int cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (mp.count(words[i]) > 0)
        {
            if (mp[words[i]] != i)
                cnt++;
        }
    }
    return cnt;
}

int stringHelper(int x, int y, int z, int last)
{
    if (last == 0 && y == 0)
        return 0;
    if (last == 2 && x == 0)
        return 0;
    if (last == 1 && (x == 0 && z == 0))
        return 0;

    if (last == 0 && y > 0)
        return 2 + stringHelper(x, y - 1, z, 1);
    else if (last == 1)
    {
        int cnt = 0;
        if (x > 0)
            cnt = 2 + stringHelper(x - 1, y, z, 0);
        if (z > 0)
            cnt = max(cnt, 2 + stringHelper(x, y, z - 1, 2));
    }

    else if (last == 2 && x > 0)
        return 2 + stringHelper(x - 1, y, z, 0);

    return 0;
}

int longestString(int x, int y, int z)
{
    int max1 = stringHelper(x - 1, y, z, 0);
    max1 = max(max1, max(stringHelper(x, y - 1, z, 1), stringHelper(x, y, z - 1, 2)));
    return max1 + 2;
}

int main()
{

    return 0;
}