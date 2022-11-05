#include <iostream>
using namespace std;

int countPoints(string rings)
{
    int r[10];
    int g[10];
    int b[10];
    for (int i = 0; i < 10; i++)
    {
        r[i] = 0;
        b[i] = 0;
        g[i] = 0;
    }
    for (int i = 0; i < rings.size(); i += 2)
    {
        if (rings[i] == 'R')
        {
            // It converts a char to an integer by subtracting the ASCII value(48) of 0 from the char
            //         '9' - '0' // 9
            //         All this is assuming that the character is between chars 0 and 9 inclusive.
            r[rings[i + 1] - '0'] = 1;
        }
        else if (rings[i] == 'G')
        {
            g[rings[i + 1] - '0'] = 1;
        }
        else
        {
            b[rings[i + 1] - '0'] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (r[i] == 1 && g[i] == 1 && b[i] == 1)
        {
            count += 1;
        }
    }
    return count;
}

int main()
{
    string stones = "aAAbcbbbd";

    return 0;
}