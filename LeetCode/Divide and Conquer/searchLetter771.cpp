#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int

bool searchLetter(char ax, string jewels, int len, int start, int end)
{
    int cdd = (int)ax;
    int mid = (start + end) / 2;
    if (len == 1)
    {
        if (ax == jewels[start])
        {
            return true;
        }
        return false;
    }

    int midd = (int)jewels[mid];
    if (cdd == midd)
    {
        return true;
    }
    else if (cdd < midd)
    {
        end = len - 1;
        return searchLetter(ax, jewels, len / 2, start, mid - 1);
    }
    else if (cdd > midd)
    {
        start = len + 1;
        return searchLetter(ax, jewels, len / 2, mid + 1, end);
    }
}

int numJewelsInStones(string jewels, string stones)
{
    int count = 0;
    int len = jewels.length();
    sort(jewels.begin(), jewels.end());
    for (int i = 0; i < len; i++)
    {
        cout << jewels[i];
    }

    for (int i = 0; i < stones.length(); i++)
    {
        char ax = stones[i];
        if (searchLetter(ax, jewels, len, 0, len))
        {
            count += 1;
        }
        else
        {
            continue;
        }
    }
    return count;
}

int main()
{
    string jewels = "adcbA";
    string stones = "aAAbcbbbd";
    int a = (int)'A';
    int b = (int)'a';
    cout << a << " " << b;
    cout << numJewelsInStones(jewels, stones);
    return 0;
}