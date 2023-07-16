// Link : https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413
// Time Complexity : O(n^4)
// Approach-> Dekho jo lcs ka length nikale ho aur dp table fill kiye ho usse bs hum length lenge aur ek recursive call krdo....
// Jisme push krega select krke index....usme phir call krke jbtk select na ho and then pop krega....just as backtracking

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation Approach - Bottom Up....hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in text1 and ind2 in text2 max longest subsequence kitna length ka h
vector<string> all_longest_common_subsequences(string s, string t)
{
    int n = text1.size();
    int m = text2.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n + 1 size rkho for 1 index shifting similar for m+1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Memoisation ka base case save krdenge
    // We will do index shifting ....agar -1 horha toh 0 pr toh n-1 ko n pr rkhdo to save base case of memoisation
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    // text 1 ke liye....n rows mein h to i rows mein aayega
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    // Text 2 k liye
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // 2 Parameter h toh 2 nested loops for ind1 and ind2...will start from 1 as 0 sbka fill h
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // If a match toh 1 add krke call on ind-1 and return..index shifting hua h toh -1 krdo as string k liye ind 0 to n-1 hi h
            if (text1[ind1 - 1] == text2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
            // its a conditional kaun execute hoga
            // Agar no match to max of dono ind jo call kroge
            else
                dp[ind1][ind2] = 0 + max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
        }
    }
    // Jo memoisation ko call kia usse hi return krdunga usme +1 krdo as index shifting dono m
    int len = dp[n][m];

    // For all the string
    //  Ab print krenge jha bhi diagonal move hua h
    int i = n, j = m;
    // Index shifting nhi h issliye equal to lgega
    string str = "";
    vector<string> ans;
    helper_print(s, t, 0, 0, str, ans, len);
    // Sort krdia for lexicographical order
    sort(ans.begin(), ans.end());
    return ans;
}

// Memoisation Approach - Top Down...hum dono ke end i.e. pure string ko call kiye and wo mjhe saara
// dp[ind1][ind2] means ki till ind1 in text1 and ind2 in text2 max longest subsequence kitna length ka h
int stringHelper(string text1, string text2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Jab koi bhi ek string k length over ho jaye toh koi match nhi horha toh usse case mein hum 0 return krdo
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // If a match toh 1 add krke call on ind-1 and return
    if (text1[ind1] == text2[ind2])
        return dp[ind1][ind2] = 1 + stringHelper(text1, text2, ind1 - 1, ind2 - 1, dp);
    // Dono match unmatch se max nhi lerhe kuuki match krrha whi 1 add krrha h and uske neeche pr jaarha and match nhi to no comparision
    // its a conditional kaun execute hoga
    // Agar no match to max of dono ind jo call kroge
    return dp[ind1][ind2] = 0 + max(stringHelper(text1, text2, ind1, ind2 - 1, dp), stringHelper(text1, text2, ind1 - 1, ind2, dp));
}

// Set to store all the strings
set<string> st;
void helper_print(string s, string t, int i, int j, string &temp, vector<string> &ans, int cnt)
{
    // Agar len 0 horha aur set mein nhi h to store it
    if (cnt == 0)
    {
        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            ans.push_back(temp);
        }
        return;
    }
    // Agar out of size horha
    if (i >= s.size() || j >= t.size())
        return;

    // Row select kro
    for (int row = i; row < s.size(); row++)
    {
        // Col select kro
        for (int col = j; col < t.size(); col++)
        {
            // kisi mein equal h tbhi chlega
            if (s[row] == t[col])
            {
                temp.push_back(s[row]);
                helper_print(s, t, row + 1, col + 1, temp, ans, cnt - 1);
                // backtrack krdia pop krke taki next string bne
                temp.pop_back();
            }
        }
    }
}

vector<string> all_longest_common_subsequences(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // 2 parameters h ind1 and ind2 toh 2D Vector use krenge
    // Dekho ind1 jo hai 0 tk jayega toh n size rkho
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int len = stringHelper(s, t, n - 1, m - 1, dp);
    // Agar ek string print krana hota to ye krte
    // Ab print krenge jha bhi diagonal move hua h
    // int i = n, j = m;
    // Index shifting nhi h issliye equal to lgega
    // string str = "";
    // for (int k = 0; k < len; k++)
    // {
    //     str.push_back('$');
    // }
    // int index = len - 1;
    // while (i >= 0 && j >= 0)
    // {
    //     if (s[i - 1] == s[t - 1])
    //     {
    //         str[index] = s[i - 1];
    //         index--;
    //         i--;
    //         j--;
    //     }
    //     else if (dp[i][j - 1] > dp[i - 1][j])
    //         j--;
    //     else
    //         i--;
    // }

    // For all the string
    //  Ab print krenge jha bhi diagonal move hua h
    int i = n, j = m;
    // Index shifting nhi h issliye equal to lgega
    string str = "";
    vector<string> ans;
    helper_print(s, t, 0, 0, str, ans, len);
    // Sort krdia for lexicographical order
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}