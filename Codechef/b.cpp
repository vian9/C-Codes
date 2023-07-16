#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int> &curr, int row, int col)
{
    for (int i = 0; i <= row - 1; i++)
    {
        if (curr[i] - 1 == col || ((abs(curr[i] - 1 - col) == 1) && (abs(i - row) == 1)))
        {
            return false;
        }
    }
    return true;
}

int helper(int row, int n, vector<int> &temp, vector<vector<int>> &ans)
{
    int count = 0;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(temp, row, col))
        {
            temp[row] = col + 1;
            if (row == n - 1)
            {
                ans.push_back(temp);
                count++;
            }
            else
            {
                helper(row + 1, n, temp, ans);
            }
        }
    }
    return count;
}

void nQueen(int n)
{
    // code here
    vector<int> temp(n, -1);
    vector<vector<int>> ans;

    cout << helper(0, n, temp, ans) << endl;
}

int main()
{
    nQueen(6);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll divSum(int num)
{
    ll result = 0;
    if (num == 1)
        return result;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == (num / i))
                result += i;
            else
                result += (i + num / i);
        }
    }

    return (result + 1);
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
        ll n;
        cin >> n;
        ll sum = divSum(n);
        if (sum == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int insert_plus(string s)
{
    stack<char> st;
    int count = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                count++;
            }
            else
            {
                st.pop();
            }
        }
    }
    return count;
}

int main()
{
    // Get the input string.
    string s;
    cin >> s;

    // Count the number of '+' characters to be inserted.
    int count = insert_plus(s);

    // Print the number of '+' characters to be inserted.
    cout << count << endl;

    return 0;
}

int minimumPlusCount(const std::string &s)
{
    int count = 0;
    std::stack<char> brackets;

    for (char c : s)
    {
        if (c == '(')
        {
            brackets.push(c);
        }
        else if (c == ')' && !brackets.empty())
        {
            brackets.pop();
        }
        else
        {
            count++; // Count the number of unmatched closing brackets
        }
    }

    // Count the number of unmatched opening brackets
    count += brackets.size();

    return count;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minimumPlusCount(string &s)
{
    int count = 0;
    int plusCount = 0;
    stack<char> brackets;

    for (char c : s)
    {
        if (c == '(')
        {
            brackets.push(c);
        }
        else if (c == ')' && !brackets.empty())
        {
            brackets.pop();
        }
        else
        {
            count++;
        }

        if (brackets.empty() && count > 0)
        {
            plusCount += (count + 1) / 2;
            count = 0;
        }
    }

    return plusCount;
}

int main()
{
    ll q;
    cin >> q;
    for (ll t = 0; t < q; t++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minimumPlusCount(s) << endl;
    }
    return 0;
}

int minimumPlusCount(string &s)
{
    int count = 0;
    stack<char> brackets;

    for (char c : s)
    {
        if (c == '(')
        {
            brackets.push(c);
        }
        else if (c == ')' && !brackets.empty())
        {
            brackets.pop();
        }
        if (brackets.empty())
        {
            count++;
        }
    }

    return count;
}

// if (brackets.empty() && count > 0)
// {
//     plusCount += (count + 1) / 2;
//     count = 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findX(int N, int Q, vector<int> &query)
{
    int diagonalNumber = 1;
    int currentValue = 1;
    int nextDiagonalValue = 2;

    for (int i = 0; i < Q; i++)
    {
        int x = query[i];

        while (currentValue < x)
        {
            if (currentValue == nextDiagonalValue)
            {
                diagonalNumber++;
                nextDiagonalValue = (diagonalNumber * (diagonalNumber + 1)) / 2;
            }
            currentValue++;
        }

        if (currentValue == x)
        {
            return diagonalNumber;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> query;
    for (int i = 0; i < q; i++)
    {
        int p;
        cin >> p;
        query.push_back(p);
    }
    cout << findX(n, q, query) << endl;
    return 0;
}