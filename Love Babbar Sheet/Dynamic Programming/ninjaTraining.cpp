// Link : https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
// Time Complexity : O()
// Approach-> Since 2 parameter aagya toh 2D vector bnega and usme ab task kro....bs dhyan rhe dp[i][j] means day is i and last task done is j to wo nhi krna h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Space Optimisation - Hume bs last 2 vector maintain krne h...day-1 ke liye prev and day k liye curr
// a particular place in a vector tells ki day 0 se day n-1 tk usse task k through max points
// dp[n-1][3] means ki maine last task 3 kia and day is n-1 tb 0 to n-1 mein kitna point aayega
// Mjhe points maximise krne h and in a way ki 2 consecutive days same na ho
// 0 se start kro and n-1 tk jayega

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    // day is 0 and last task is 0 toh points uske alawa hoga
    prev[0][0] = max(points[0][1], points[0][2]);
    prev[0][1] = max(points[0][0], points[0][2]);
    prev[0][2] = max(points[0][1], points[0][0]);
    prev[0][3] = max(points[0][1], max(points[0][0], points[0][2]));

    // choosen a day
    for (int day = 1; day < n; day++)
    {
        // day-1 is prev and day is curr vector jo maintain krna h
        vector<int> curr(4, -1);
        // Last task
        for (int last = 0; last < 4; last++)
        {
            // For a day and a last wo 3 mein se 2 task krega
            curr[last] = 0;
            int maxi = 0;
            // Ye recurrence se as it is copy...to choose the task
            for (int task = 0; task < 3; task++)
            {
                // Jo last task kia h wo nhi krenge
                if (last != task)
                {
                    // Isse task k points and jo last day whi task kia uske points ko sum kro
                    int point = points[day][task] + prev[task];
                    maxi = max(point, maxi);
                }
            }
            // with this day and last work jo max possible task k kya hoga
            curr[last] = maxi;
        }
        prev = curr;
    }

    return prev[3];
}

// Tabulation - Bottom Up Approach
// a particular place in a vector tells ki day 0 se day n-1 tk usse task k through max points
// dp[n-1][3] means ki maine last task 3 kia and day is n-1 tb 0 to n-1 mein kitna point aayega
int ninjaHelper(vector<vector<int>> &points, int n, vector<vector<int>> &dp)
{
    // day is 0 and last task is 0 toh points uske alawa hoga
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][0], points[0][2]));

    // choosen a day
    for (int day = 1; day < n; day++)
    {
        // Last task
        for (int last = 0; last < 4; last++)
        {
            // For a day and a last wo 3 mein se 2 task krega
            dp[day][last] = 0;
            int maxi = 0;
            // Ye recurrence se as it is copy...to choose the task
            for (int task = 0; task < 3; task++)
            {
                // Jo last task kia h wo nhi krenge
                if (last != task)
                {
                    // Isse task k points and jo last day whi task kia uske points ko sum kro
                    int curr = points[day][task] + dp[day - 1][task];
                    maxi = max(curr, maxi);
                }
            }
            // with this day and last work jo max possible task k kya hoga
            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][3];
}

// Mjhe points maximise krne h and in a way ki 2 consecutive days same na ho
// 0 se start kro and n-1 tk jayega
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // n * 4 ka array kuuki 0,1,2 toh values h and ek first index k liye hai jisme all combinations lena h
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaHelper(points, n, dp);
}

// Memoisation - Top Down Approach
// A particular place in a vector tells mein ki max Point usse din se wo last task se 0 day tk kitna hoga - dp[n-1][3]...3 is last task
int ninjaHelper(vector<vector<int>> &points, int n, int day, int last, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }

        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    // Harr k liye task krenge pick jo last time nhi kia h and usme se max ko dalenge
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int curr = points[day][task] + ninjaHelper(points, n, day - 1, task, dp);
            maxi = max(maxi, curr);
        }
    }
    return dp[day][task] = maxi;
}

// Mjhe points maximise krne h and in a way ki 2 consecutive days same na ho
// 0 se start kro and n-1 tk jayega
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // n * 4 ka array kuuki 0,1,2 toh values h and ek first index k liye hai jisme all combinations lena h
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaHelper(points, n, n - 1, 3, dp);
}

// Recursive - Top Down Approach
int ninjaHelper(vector<vector<int>> &points, int n, int ind, int last)
{
    if (ind == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }

        return maxi;
    }
    if (ind < 0)
    {
        return 0;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int curr = points[ind][i] + ninjaHelper(points, n, ind - 1, i);
            maxi = max(maxi, curr);
        }
    }
    return maxi;
}

// Mjhe points maximise krne h and in a way ki 2 consecutive days same na ho
// 0 se start kro and n-1 tk jayega
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return ninjaHelper(points, n, n - 1, -1);
}

int main()
{

    return 0;
}