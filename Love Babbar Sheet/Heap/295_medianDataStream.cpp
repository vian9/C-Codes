// Link : https://leetcode.com/problems/find-median-from-data-stream/description/
// Time Complexity : O()
// Approach-> Data ko 2 part mein divide kro left side mein median se kaam jo maxHeap cover kre....right side mein jada jo minHeap cover kre
// Ab size kisse ka jada bada horha h to idhar se udhar shift krdo and at a moment maxHeap will be 1 element more than minHeap

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Max heap
priority_queue<int> maxi;
// Min heap
priority_queue<int, vector<int>, greater<int>> mini;
MedianFinder()
{
}

// Dekho x agar median h to x ke left mein and right mein same count of number hoga
// Now ab bs ab ye make sure kro ki x ke left mein sb x se chota ho ye hoga maxHeap se and x ke right mein sbse bada ho ye hoga minHeap se
// Ab agar even number h total...toh maxHeap k max and minHeap k min k sum by 2 hoga ans
void addNum(int num)
{
    // MaxHeap is vacant or top element is larger than the num
    if (maxi.size() == 0 || maxi.top() >= num)
    {
        maxi.push(num);
    }
    // Otherwise top element of maxi is smaller than num to right side minHeap m aayega
    else
    {
        mini.push(num);
    }

    // Agar maxi k size jada bada h to ek element nikalkr minHeap  m daldo...at a moment maxHeap will have one element more than minHeap
    if (maxi.size() > mini.size() + 1)
    {
        mini.push(maxi.top());
        maxi.pop();
    }
    else if (mini.size() > maxi.size())
    {
        maxi.push(mini.top());
        mini.pop();
    }
}

double findMedian()
{
    // agar even ho toh dono mein equal no of numbers honge
    if (maxi.size() == mini.size())
    {
        return (maxi.top() * 1.00 + mini.top() * 1.00) / 2;
    }

    // agar odd ho toh maxHeap return krdo as it will have one more element

    return maxi.top();
}

int main()
{

    return 0;
}