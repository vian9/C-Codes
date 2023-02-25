// Link : https://leetcode.com/problems/make-the-string-great/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// we have to make such that next wla same na ho....stack m push krte jao....agar current same as top to pop

string makeGood(string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    string val;
    val.push_back(s[0]);
    int ascii = val.back();
    for (int i = 1; i < s.length(); i++)
    {
        int current = s[i];
        if (abs(ascii - current) == 32)
        {
            val.pop_back();
            if (val.empty())
            {
                val.push_back(s[i + 1]);
                ascii = val.back();
                i += 1;
            }
            else
            {
                ascii = val.back();
            }
        }
        else
        {
            ascii = current;
            val.push_back(s[i]);
        }
    }
    if (val.length() == 0)
    {
        return "";
    }
    return val;
}

string makeGood(string s)
{

    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        ans.push_back(s[i]);

        while (ans.size() && (ans.back() == s[i + 1] + 32 || ans.back() == s[i + 1] - 32))
        {
            ans.pop_back();
            i++;
        }
    }
    cout << ans.length();
    return ans;
}

int main()
{

    return 0;
}