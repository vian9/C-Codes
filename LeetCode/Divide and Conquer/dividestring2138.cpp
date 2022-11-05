#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int

vector<string> divideString(string s, int k, char fill)
{
    vector<string> v;
    int m = s.size();

    for (int i = 0; i < m; i++)
    {
        if (k + i < m)
        {
            v.push_back(s.substr(i, k));
            i += k - 1;
        }
        else
        {
            string str;
            int c = k;
            while (c--)
            {
                if (i != m)
                {
                    str.push_back(s[i]);
                    i++;
                }
                else
                {
                    str.push_back(fill);
                }
            }
            v.push_back(str);
        }
    }
    return v;
}

int main()
{
    string stones = "aAAbcbbbd";
    divideString(stones, 3, 'x');
    return 0;
}