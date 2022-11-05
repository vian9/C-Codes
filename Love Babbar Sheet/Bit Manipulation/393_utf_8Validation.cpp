// Link : https://leetcode.com/problems/utf-8-validation/
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void bin(int n, vector<int> &binary)
{
    vector<int> ans;
    while (n > 0)
    {
        // storing remainder in binary array
        ans.push_back(n % 2);
        n = n / 2;
    }
    reverse(ans.begin(), ans.end());
    int p = ans.size();
    vector<int> second(8 - p, 0);
    binary.insert(binary.begin(), second.begin(), second.end());
    binary.insert(binary.end(), ans.begin(), ans.end());
}

bool check(int start, int count, vector<vector<int>> binaries)
{
    for (int i = start + 1; i < start + count; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                if (binaries[i][j] != 1)
                    return false;
            }
            else
            {
                if (binaries[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool validUtf8(vector<int> &data)
{
    vector<vector<int>> binaries;
    for (int i = 0; i < data.size(); i++)
    {
        vector<int> binary;
        bin(data[i], binary);
        binaries.push_back(binary);
    }

    for (int i = 0; i < binaries.size(); i++)
    {
        int count = 0;
        if (binaries[i][0] == 0)
        {
            if (binaries[i][0] != 0)
                return false;
        }
        else
        {
            int j = 0;
            while (binaries[i][j] != 0)
            {
                count++;
                j++;
            }
            if (!check(i, count, binaries))
                return false;
        }
        i += (count - 1);
    }
    return true;
}

int main()
{

    return 0;
}