// Link : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// Time Complexity : O()
// Approach-> Max Deadline nikalo jobs ko profit k basis pr sort kro and then jobs ko schedule kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

static bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    // each job will take 1 unit of time...job id, deadline and profit
    vector<pair<int, int>> jobs;
    int maxDead = 0;
    for (int i = 0; i < n; i++)
    {
        jobs.push_back({arr[i].profit, arr[i].dead});
        maxDead = max(maxDead, arr[i].dead);
    }
    // Ab maxDead nikl lia to koi bhi job usse phle hi aayega
    vector<int> schedule(maxDead, -1);
    // sort from max profit to min
    sort(jobs.begin(), jobs.end(), compare);
    int count = 0;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        // Ab harr task ko lo based on max profit and phir check kro schedule kr skte ho ya nhi
        int currDead = jobs[i].second;
        int currProfit = jobs[i].first;
        // agar currDead 3 hai to wo 0 to 3-1=2 0 to 2 k beech m schedule hona chahiye to wo position hum schedule array m dekhenge
        for (int k = currDead - 1; k >= 0; k--)
        {
            if (schedule[k] == -1)
            {
                schedule[k] = 1;
                count++;
                profit += currProfit;
                break;
            }
        }
    }
    return {count, profit};
}

int main()
{

    return 0;
}