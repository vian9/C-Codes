// Link : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// Time Complexity : O(N) and Space O(1)
// Approach-> Sort krdo alag alag and now pick by ki kaun sa train departure se phle aarha h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function to find the minimum number of platforms required at the
// railway station such that no train waits.

// Hard to think....O(nlogn)
int findPlatform(int arr[], int dep[], int n)
{
    // Dono ko alag alag sort krdo
    sort(arr + 0, arr + n);
    sort(dep + 0, dep + n);

    // Ab jitna baar bhi kisi train k arrival kisi ka departure se phle h we need that much platforms as tbtk platform occupied h jo aaya hoga usse dep pr
    int count = 0;
    int j = 0;
    int endTime = dep[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > endTime)
        {
            j++;
            endTime = dep[j];
        }
        else
        {
            count++;
        }
    }
    return count;
}

// Most intuitive solution will be constraint is 2361 possibility to utna ka array lelo
int findPlatform(int arr[], int dep[], int n)
{
    // 24 hours m 0 to 2359 tk hoga
    vector<int> platform(2361, 0);
    // Ab ek time pr jitna arrival hua uske liye +1 and jitna baar usse time pr depart uske liye -1 kro...they are the conflicting ones
    for (int i = 0; i < n; i++)
    {
        platform[arr[i]]++;
        // Jaise hi khali hua uske agla k liye platform ek kaam krdo
        platform[dep[i] + 1]--;
    }

    int reqPlatform = 0;
    int count = 0;
    for (int i = 0; i < platform.size(); i++)
    {
        // Ab kisi bhi minute pr cumulative platform kitna chahiye wo dekho....agar cumulative platform required is more than update reqPlatform
        count += platform[i];
        reqPlatform = max(count, reqPlatform);
    }
    return reqPlatform;
}

int main()
{

    return 0;
}