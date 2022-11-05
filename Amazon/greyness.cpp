// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getMaximumGreyness(vector<string> pixels)
{
    int max = INT_MIN;
    int n = pixes.size();
    int m = pixes[0].length();
    vector<int> black;
    vector<int> white;
    for (int i = 0; i < pixels.size(); i++)
    {
        int count0 = 0;
        int count1 = 1;
        for (int j = 0; j < m; j++)
        {
            if (pixels[i][j] == '0')
                count0++;
            else
                count1++;
        }
        black.push_back(count1);
        white.push_back(count0);
    }
}

int main()
{

    return 0;
}