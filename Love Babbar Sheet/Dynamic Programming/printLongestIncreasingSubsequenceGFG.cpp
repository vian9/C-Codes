// Link : https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/
// Time Complexity : O(n*n) SC:O(n)
// Refer LIS problem 300 on leetcode
// Approach-> Strictly increasing subsequence chahiye...toh hume last janna hoga and usse greater h tbhi pick kro wrna skip kro....ab last janne k liye value
// ka range mt lo balki index ka range lo aasan pdega
// So bs index ka dhyan rkho baaki same recursive code memoisation ka use krenge
// Ab hum dp table bnayenge and uske prev tk saara iterate krke dekhenge and jha usse bada aayega update krdenge dp[i] to get biggest LIS till that ind
// Last mein max LIS le lenge saara dp[ind] mein se
// Ab print krne k liye hume hash jisse wo dp table update hua h wo chahiye...to hum jb bhi update krenge dp[ind] to jisse last k karan horha wo bhi lastIndex hoga daldenge
// Ab lastIndex lelo jisse max LIS aarha and phir usko array mein push kro and ek loop mein jbtk hash ka value same lastIndex ko point na kre chlte rho

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Tabulation Using a single DP Array to store the LIS
// dp[i] means the largest LIS Possible till index i in arr
// Hume jo phle tabulation mein mila value usse hum derive kiye ki kaise ye table bna hoga and phir usse table bnaye and update kiye
vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    // declare a single dp array with default value 1 as bs whi ind k element consider krenge to 1 hoga hi minimum
    vector<int> dp(n, 1);

    int maxi = -1;
    int lastIndex = -1;
    // Ab ye hash se hum jo subsequence mein curr ke alwa last index dalenge wo hash mein dal denge and hum LIS track kr payenge
    vector<int> hash(n, -1);
    // Ab ind pr loop iterate krenge aur value nikalenge
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        // Ab last jo h 0 se start hokr ind-1 tk jayega
        for (int last = 0; last <= ind - 1; last++)
        {
            // Ab current value prev se bada h to 1+dp[last] le lenge and compare krke max le lenge and jo last h wo hum
            // subsequence ka last value dekhrhe max and usme apne ind wla add kr derhe
            // Jb current dp[ind] value se bada ho tbhi update krenge and then hash mein bhi last index update krenge
            if (arr[ind] > arr[last] && dp[ind] < 1 + dp[last])
            {
                dp[ind] = 1 + dp[last];
                hash[ind] = last;
            }
        }
        // Update krdia maxi LIS ko and whi hum LIS ka lastIndex bhi update krenge sbse bade value ka
        if (maxi < dp[ind])
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> lis;
    // Sbse last element push krdia
    lis.push_back(arr[lastIndex]);
    // 1st way
    //  maxi kaam krdia
    //  nmaxi--;
    //  Hum ye loop ka lastIndex jb -ve ya 0 ho jaye kuch aise krke nhi lga skte h....hume maxi pta h LIS k length h jbtk wo 0 se bada h utna len hume milgya
    //  while (maxi > 0)
    //  {
    //      lastIndex = hash[lastIndex];
    //      lis.push_back(arr[lastIndex]);
    //      maxi--;
    //  }

    // 2nd way....jaise hi hash ka lastIndex ka value same ko point na krde
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }

    // Reverse order mein LIS aaya h just reverse it
    reverse(lis.begin(), lis.end());

    return lis;
}

int main()
{

    return 0;
}