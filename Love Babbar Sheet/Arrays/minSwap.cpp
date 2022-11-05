// VVI .....many CP Questions based on this
// Link : https://www.codingninjas.com/codestudio/problems/minimum-swaps-to-sort-array_1806885?topList=love-babbar-dsa-sheet-problems
// Time Complexity : O(nlogn)
// Approach-> Ek vector lia having pair jisme number and uska index store kia....phir usse vector ko sort krdia on basis of value
// ab ek loop lagaya and check kia ki index stored and i same h to thik h otherwise swap krdo v[i] ko with that index pr se a
// ab isse k count is the ans and haan harr baar swap pr i-- kuuki phir se check

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minSwaps(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        p.first = arr[i];
        p.second = i;
        sorted[i] = p;
    }

    // By default sort function sorts on basis of 1st element in the pair....2nd element k liye use bool compare function
    // and return on compare a.second < b.second in it
    sort(sorted.begin(), sorted.begin() + n);
    for (int i = 0; i < n; i++)
    {
        if (sorted[i].second == i)
        {
            continue;
        }
        else
        {
            count++;
            swap(sorted[i], sorted[sorted[i].second]);
            i--;
        }
    }

    return count;
}

int main()
{

    return 0;
}