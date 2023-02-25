// Link : https://leetcode.com/problems/detect-capital/
// Time Complexity : O(n)
// Approach-> Bss check for capital and small k sequence

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// space se check krna h
bool detectCapitalUse(string word)
{

    for (int i = 0; i < word.length(); i++)
    {
        int j = i;
        int count = 0; // for first letter
        int last = 0;  // for last letter
        while (word[j] != ' ' && j < word.length())
        {
            char st = word[j];
            int p = (int)st;
            if (count == 0 && j == 0)
            {
                // agar phla letter capital hogya to 1 krdo
                if (p >= 65 && p <= 90)
                {
                    count = 1;
                    last = 1;
                }
            }
            else if (j > 0)
            {
                // ab capital m 2 cases all capital or 1st capital
                if (count == 1)
                {
                    // small hokr achanak se capital nhi
                    if (last == 0)
                    {
                        if (p >= 65 && p <= 90)
                            return false;
                    }
                    // ab capital h
                    else if (last == 1)
                    {
                        // ab 2nd capital ya small ho skta h
                        if (j == 1)
                        {
                            if (p > 90)
                                last = 0;
                        }
                        // ab saara capital hona chahiye
                        else if (j > 1)
                        {
                            if (p > 90)
                                return false;
                        }
                    }
                }
                // small m sav small
                else if (count == 0)
                {
                    if (p >= 65 && p <= 90)
                        return false;
                }
            }
            j++;
        }
        i = j;
    }

    return true;
}

int main()
{

    return 0;
}