// Link : https://leetcode.com/problems/lemonade-change/submissions/
// Time Complexity : O(n)
// Approach-> Bs dekhlo kitna aaya and uske case m kitna return krna h and uska count maintain krlo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Isme five ten and twenty k count rkhlo and as we know bs whi values aa skta h....
bool lemonadeChange(vector<int> &bills)
{
    int n = bills.size();
    if (n == 1)
    {
        if (bills[0] == 5)
            return true;
        return false;
    }
    // sort nhi kr skte as in queue
    int total = 0;
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for (int i = 0; i < n; i++)
    {
        int returnVal = bills[i] - 5;
        // five m to kuch return nhi krna h
        if (bills[i] == 5)
            five++;
        // ten k case m five return kro nhi h five to false
        else if (bills[i] == 10)
        {
            ten++;
            if (five == 0)
                return false;
            else
                five--;
        }
        else
        {
            // twenty k case m 15 return kro either by 3 five or five and ten and nhi h to false
            twenty++;
            if (five > 0 && ten > 0)
            {
                five--;
                ten--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool lemonadeChange(vector<int> &bills)
{
    int n = bills.size();
    if (n == 1)
    {
        if (bills[0] == 5)
            return true;
        return false;
    }
    // sort nhi kr skte as in queue
    int total = 0;
    int five = 0;
    int ten = 0;
    int twenty = 0;
    for (int i = 0; i < n; i++)
    {
        int returnVal = bills[i] - 5;
        if (returnVal != 0)
        {
            if (returnVal > total)
            {
                return false;
            }
            // this method will work for even paying 100
            // twenty h to kitna note hum twenty se return kr skte h
            // waise hi 10 and 5
            if (twenty > 0)
            {
                int note = returnVal / 20;
                if (twenty >= note)
                {
                    returnVal -= (20 * note);
                    twenty -= note;
                }
                else
                {
                    returnVal -= (20 * twenty);
                    twenty = 0;
                }
            }
            if (ten > 0)
            {
                int note = returnVal / 10;
                if (ten >= note)
                {
                    returnVal -= (10 * note);
                    ten -= note;
                }
                else
                {
                    returnVal -= (10 * ten);
                    ten = 0;
                }
            }
            if (five > 0)
            {
                int note = returnVal / 5;
                cout << note;
                if (five >= note)
                {
                    returnVal -= (5 * note);
                    five -= note;
                }
                else
                {
                    returnVal -= (5 * five);
                    five = 0;
                }
            }
        }
        // ab check krlo and jo note aaya usse update krdo
        if (returnVal != 0)
            return false;
        total += bills[i];
        if (bills[i] == 5)
            five++;
        else if (bills[i] == 10)
            ten++;
        else
            twenty++;
    }
    return true;
}

int main()
{

    return 0;
}