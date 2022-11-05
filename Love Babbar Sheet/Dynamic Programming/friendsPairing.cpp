// Link : https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countFriendsPairings(int n)
{
    int total = n * (n - 1);
    total = total / 2;
    total = total + 1;
    int num = 1e9 + 7;
    return total % (num);
}

int main()
{

    return 0;
}