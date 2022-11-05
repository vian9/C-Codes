// Link : https://leetcode.com/problems/container-with-most-water/
// Time Complexity : O(n)
// Approach-> 2 Pointer with Greedy

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Since maximise krna h toh DP or Greedy.....constraints is high to Greedy
int maxArea(vector<int> &height)
{
    int maxAreaPos = 0;
    // need to know the exact position of the two towers
    // Left and right 2 pointer lelia and move krenge
    int left = 0;
    int right = height.size() - 1;
    while (left < right)
    {
        int localArea = min(height[left], height[right]) * (right - left);
        if (maxAreaPos < localArea)
            maxAreaPos = localArea;
        // left ya right move krenge on expectation ki isse jada bara bar milega
        if (height[left] > height[right])
            right--;
        else
            left++;
    }

    return maxAreaPos;
}

int main()
{

    return 0;
}