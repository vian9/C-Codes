// Link : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Time Complexity : O()
// Approach-> Dekho weight per profit se sort kro and pick krte jao jbtk weight jada ho...last m fraction of weight pick kro
// Bs dhyan ye rkhna h ki jo values h wo double m type cast krke rkho

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Item
{
    int value;
    int weight;
};

static bool compare(pair<int, int> a, pair<int, int> b)
{
    // Value per weight in decreasing order sort
    return ((double)a.first / (double)a.second) > ((double)b.first / (double)b.second);
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, int>> items;
    for (int i = 0; i < n; i++)
    {
        items.push_back({arr[i].value, arr[i].weight});
    }
    sort(items.begin(), items.end(), compare);
    double value = 0;
    int weight = W;
    for (int i = 0; i < items.size(); i++)
    {
        // cout<<items[i].second<<" "<<items[i].first<<endl;
        // Jbtk bag k weight se chota tbtk value direct add in double
        if (weight >= items[i].second)
        {
            weight -= items[i].second;
            // Ye 1.00 se multiply taki 2 decimal tk rhe
            value += ((double)items[i].first * 1.00);
        }
        else
        {
            // otherwise valueper weight se remaining weight aayega
            int remWeight = weight;
            double valuePerWeight = ((double)items[i].first * 1.00) / (double)items[i].second;
            weight = 0;
            // Ye 2 decimal tk value rkhne k liye 1.00 se multiply
            value += (valuePerWeight * (double)remWeight * 1.00);
            break;
        }
    }
    return value;
}

int main()
{

    return 0;
}