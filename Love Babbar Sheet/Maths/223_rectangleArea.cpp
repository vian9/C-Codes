// Link : https://leetcode.com/problems/rectangle-area/description/
// Time Complexity : O(1)
// Approach-> Dono ka area nikal lo....and finally overlap x and y coordinates nikal lo and usse overlap area nikal do
// it will give the total area by the shape

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    // dono ka area nikal do and overlap ka area subtract kr denge
    int area1 = abs(ax2 - ax1) * abs(ay2 - ay1);
    int area2 = abs(bx2 - bx1) * abs(by2 - by1);

    // will calculate the overlap area
    int overlapArea = 0;
    int xOverlap = min(ax2, bx2) - max(ax1, bx1);
    int yOverlap = min(ay2, by2) - max(ay1, by1);

    // ab agar dono overlap 0 se bada h tbhi area cover krega
    if (xOverlap > 0 && yOverlap > 0)
    {
        overlapArea = abs(xOverlap * yOverlap);
    }
    return area1 + area2 - overlapArea;
}

int main()
{

    return 0;
}