// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Time Complexity : O()
// Approach-> Ek number lo uspr start kisse krna uske liye iterate and then uske corresponding call krdo and next digit pr wo de dega

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void myCombo(vector<string> &ans, string &s, string digits, unordered_map<int, string> &mp, int index)
{
    // Base case is jaise hi saare digits cover hogye
    if (index >= digits.length())
    {
        ans.push_back(s);
        return;
    }

    // Phla digit lelo index ka and uske corresponding char lelo
    int dig = digits[index] - '0';
    string value = mp[dig];
    // Phle k liye char dalo and call on next digit and then pop out for next
    for (int i = 0; i < value.length(); i++)
    {
        s.push_back(value[i]);
        myCombo(ans, s, digits, mp, index + 1);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
    {
        vector<string> ans;
        return ans;
    }
    // map m string store krlia
    unordered_map<int, string> mp;
    mp[0] = "";
    mp[1] = "";
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";
    vector<string> ans;
    string s;
    myCombo(ans, s, digits, mp, 0);
    return ans;
}

int main()
{

    return 0;
}