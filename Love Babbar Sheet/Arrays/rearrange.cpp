// Link : https://www.codingninjas.com/codestudio/problems/rearrange-alternatively_873851?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(n)
// Approach-> Phle pos and neg k vector lelia uska total count....ab 1st me pos phir negative enter krte gye
// also make sure ki agar pura neg over to pos ko enter krdo pura

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void rearrange(vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;
    int posc = 0;
    int negc = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
            posc++;
        }
        else
        {
            neg.push_back(arr[i]);
            negc++;
        }
    }
    int j = 0, k = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((i % 2 == 0 && posc > 0) || negc == 0)
        {
            arr[i] = pos[j];
            j++;
            posc--;
        }
        else if ((i % 2 != 0 && negc > 0) || posc == 0)
        {
            arr[i] = neg[k];
            k++;
            negc--;
        }
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        arr.push_back(j);
    }
    rearrange(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}