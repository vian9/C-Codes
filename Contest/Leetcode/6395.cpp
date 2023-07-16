// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int buyChoco(vector<int> &prices, int money)
{
    sort(prices.begin(), prices.end());
    int sum = prices[0] + prices[1];
    if (sum <= money)
    {
        return (money - sum);
    }
    return money;
}

long long maxStrength(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    sort(nums.begin(), nums.end());
    int negCount = 0;
    int zeroCount = 0;
    int posCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zeroCount++;
        else if (nums[i] < 0)
            negCount++;
        else
            posCount++;
    }
    long long product = 1;
    if (negCount % 2 != 0)
        negCount -= 1;
    if (posCount == 0 && (zeroCount > 0 && negCount == 0))
        return 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            continue;
        else if (nums[i] < 0 && negCount > 0)
        {
            product *= nums[i];
            negCount--;
        }
        else if (nums[i] > 0)
        {
            product *= nums[i];
        }
    }
    return product;
}
void myCombo(string &s, int index, vector<string> &ans, string &st, int mini)
{
    if (index >= s.length())
    {
        if (st.length() >= mini)
            ans.push_back(st);
        return;
    }

    st.push_back(s[index]);
    myCombo(s, index + 1, ans, st, mini);
    st.pop_back();
    myCombo(s, index + 1, ans, st, mini);
}

int minExtraChar(string s, vector<string> &dictionary)
{
    unordered_map<string, int> mp;
    for (int i = 0; i < dictionary.size(); i++)
    {
        mp[dictionary[i]] = 1;
    }
    unordered_map<char, int> mp2;
    for (int i = 0; i < s.length(); i++)
    {
        mp2[s[i]] = i;
    }

    string f = s;
    for (auto i : mp)
    {
        size_t found = s.find(i.first);
        size_t found2 = f.find(i.first);
        int m = 0;
        int n = 0;
        string p = s;
        if (found2 <= f.length())
        {
            f.erase(found2, i.first.length());
            m = f.length();
            for (int j = 0; j < i.first.length(); j++)
            {
                mp2.erase(i.first[j]);
            }
        }
        vector<char> st;
        if (found <= s.length())
        {
            p.erase(found, i.first.length());
            n = p.length();
            for (int j = 0; j < i.first.length(); j++)
            {
                mp2.erase(i.first[j]);
            }
        }
        if (n < m)
            f = p;

        if (found2 >= f.length() && found >= s.length())
        {
            int last = mp2[i.first[0]];
            bool check = true;
            for (int j = 1; j < i.first.length(); j++)
            {
                if (mp2.count(i.first[j]) > 0 && mp2[i.first[j]] > last)
                {
                    last = mp2[i.first[j]];
                }
                else
                    check = false;
            }
            for (int j = 0; j < i.first.length(); j++)
            {
                mp2.erase(i.first[j]);
            }
        }
    }

    return mp2.size();
}
int main()
{

    return 0;
}