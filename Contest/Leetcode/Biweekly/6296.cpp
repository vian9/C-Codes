// Link :
// Time Complexity : O()
// Approach->

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int alternateDigitSum(int n)
{
    int num = n;
    stack<int> st;
    while (num > 0)
    {
        int dig = num % 10;
        st.push(dig);
        num = num / 10;
    }
    int sum = 0;
    bool left = true;
    while (!st.empty())
    {
        int dig = st.top();
        st.pop();
        if (left)
        {
            left = false;
            sum += dig;
        }
        else
        {
            left = true;
            sum -= dig;
        }
    }
    return sum;
}

int main()
{

    return 0;
}