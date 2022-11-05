// Link : https://leetcode.com/problems/goal-parser-interpretation/
// Time Complexity : O(n)
// Approach-> Take a string and just add on condition as per which character comes in command.
// If '(' comes then check for next character if it is ')' add "o" in string and
// update i by 1 as i++ will happen after each iteration resulting i to move by 2 positions.
// Similary if it's "al" after '(' then add "al" to string and update i by 2.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string interpret(string command)
{
    // G -> G ,()->o , (al)->al
    string ans = "";
    for (int i = 0; i < command.length(); i++)
    {
        if (command[i] == 'G')
        {
            ans += "G";
        }
        else if (command[i] == '(')
        {
            if (command[i + 1] == ')')
            {
                ans += "o";
                i += 1;
            }
            else
            {
                continue;
            }
        }
        else if (command[i] == 'a')
        {
            ans += "al";
            i += 2;
        }
    }
    return ans;
}

int main()
{

    return 0;
}