// Link : https://leetcode.com/problems/design-browser-history/
// Time Complexity : O()
// Approach-> Stack lo and usme dalte jao jbtk bole
// Doubly ended LL bhi le skte h

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class BrowserHistory
{
public:
    stack<string> forw, backw;
    BrowserHistory(string homepage)
    {
        backw.push(homepage);
    }

    void visit(string url)
    {
        backw.push(url);
        // History forward k clear krna h
        while (!forw.empty())
        {
            forw.pop();
        }
    }

    string back(int steps)
    {

        // Back history minimum ek rehna chahiye
        while (backw.size() > 1 && steps > 0)
        {
            string front = backw.top();
            steps--;
            backw.pop();
            forw.push(front);
        }
        return backw.top();
    }

    string forward(int steps)
    {
        // Forward history 0 tk jaa skta h
        while (forw.size() > 0 && steps > 0)
        {
            string front = forw.top();
            forw.pop();
            backw.push(front);
            steps--;
        }
        return backw.top();
    }
};

int main()
{

    return 0;
}