#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int total, marks;
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = 0, z = 0;
        cin >> total >> marks;
        int maxMarks = (3 * total);
        int value = marks + total;
        if (marks % 3 == 0)
        {
            x += marks / 3;
        }
        else if (marks % 3 == 1)
        {
            x += (marks / 3) + 1;
            y = 2;
        }
        else if (marks % 3 == 2)
        {
            x += (marks / 3) + 1;
            y = 1;
        }
        if (x + y <= total)
        {
            cout << "YES" << endl;
            cout << x << " " << y << " " << total - x - y << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        // if (marks <= maxMarks)
        // {
        //     // int value = marks + total;
        //     // int p = value / 4;
        //     // for (int j = 1; j <= p; j++)
        //     // {
        //     //     x = j;
        //     //     z = value - (4 * j);
        //     //     y = (3 * j) - marks;
        //     //     if (y >= 0)
        //     //     {
        //     //         if (x + y + z == total)
        //     //         {
        //     //             break;
        //     //         }
        //     //     }
        //     // }
        //     // if (y >= 0)
        //     // {
        //     //     if (x + y + z == total)
        //     //     {
        //     //         cout << "YES" << endl;
        //     //         cout << x << " " << y << " " << z << endl;
        //     //     }
        //     //     else
        //     //     {
        //     //         cout << "NO" << endl;
        //     //     }
        //     // }
        //     // else
        //     // {

        //     //     cout << "NO" << endl;
        //     // }
        // }
        // else
        // {
        //     {
        //         cout << "NO" << endl;
        //     }
        // }
    }

    return 0;
}