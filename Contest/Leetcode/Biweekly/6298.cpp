// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool makeStringsEqual(string s, string target)
{
    if (s.length() != target.length())
    {
        return false;
    }
    bool saw1 = false;
    int len = s.length();
    bool saw2 = false;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
            saw1 = true;
        if (target[i] == '1')
            saw2 = true;

        if (saw1 && saw2)
            return true;
    }
    if (!saw1 && !saw2)
        return true;
    return false;
}

int main()
{

    return 0;
}