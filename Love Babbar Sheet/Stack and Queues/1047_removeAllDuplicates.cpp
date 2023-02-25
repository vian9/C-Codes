// Link : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Time Complexity : O(n)
// Approach-> Phle string ko as a stack lia and then stack m push kro....now check kro if current and next same h..
// agar hai to pop krdo
// Similar to 1554

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string removeDuplicates(string s)
{
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        ans.push_back(s[i]);
        // either jbtk milrha and size stack ka 0 na ho
        while (ans.size() && (s[i + 1] == ans.back()))
        {
            ans.pop_back();
            i++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}