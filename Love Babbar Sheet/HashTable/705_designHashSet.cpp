// Link : https://leetcode.com/problems/design-hashset/submissions/
// Time Complexity : O()
// Approach-> Vector lelo and usme initialise krte time size declare krlo and 0 and 1 se value change krlo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class MyHashSet
{
    vector<int> mp;

public:
    MyHashSet()
    {
        mp.resize(1e6 + 1);
    }

    void add(int key)
    {
        mp[key] = 1;
    }

    void remove(int key)
    {
        mp[key] = 0;
    }

    bool contains(int key)
    {
        if (mp[key] == 1)
            return true;

        return false;
    }
};

int main()
{

    return 0;
}