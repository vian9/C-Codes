#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int p, q;
        cin >> p >> q;
        string str1 = "";
        string str2 = "";

        if (p % 2 != 0 && q % 2 != 0)
        {
            cout << "-1" << endl;
            continue;
        }
        else if (p == 1 || q == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        else if (p % 2 == 0 && q % 2 == 0)
        {
            for (int i = 0; i < p / 2; i++)
            {
                str1 += 'a';
            }
            for (int i = p / 2; i < (p + q - (p / 2)); i++)
            {
                str1 += 'b';
            }
            for (int i = (p + q - (p / 2)); i < (p + q); i++)
            {
                str1 += 'a';
            }
            cout << str1 << endl;
            for (int i = 0; i < q / 2; i++)
            {
                str2 += 'b';
            }
            for (int i = q / 2; i < (p + q - (q / 2)); i++)
            {
                str2 += 'a';
            }
            for (int i = (p + q - (q / 2)); i < (p + q); i++)
            {
                str2 += 'b';
            }
            cout << str2 << endl;
        }
        else if ((p + q) % 2 != 0)
        {
            if (p % 2 != 0)
            {
                for (int i = 0; i < q / 2; i++)
                {
                    str1 += 'b';
                }
                for (int i = q / 2; i < (p + q - (q / 2)); i++)
                {
                    str1 += 'a';
                }
                for (int i = (p + q - (q / 2)); i < (p + q); i++)
                {
                    str1 += 'b';
                }
                cout << str1 << endl;

                char tp1;
                char tp2;

                tp1 = str1[q / 2];
                str1[q / 2] = str1[(q / 2) - 1];
                str1[(q / 2) - 1] = tp1;

                tp2 = str1[(p + q) - (q / 2)];
                str1[(p + q) - (q / 2)] = str1[(p + q) - (q / 2) - 1];
                str1[(p + q) - (q / 2) - 1] = tp2;
                cout << str1 << endl;
            }

            else if (q % 2 != 0)
            {
                for (int i = 0; i < p / 2; i++)
                {
                    str1 += 'a';
                }
                for (int i = p / 2; i < (p + q - (p / 2)); i++)
                {
                    str1 += 'b';
                }
                for (int i = (p + q - (p / 2)); i < (p + q); i++)
                {
                    str1 += 'a';
                }
                cout << str1 << endl;

                char tp1;
                char tp2;

                tp1 = str1[p / 2];
                str1[p / 2] = str1[(p / 2) - 1];
                str1[(p / 2) - 1] = tp1;

                tp2 = str1[(p + q) - (p / 2)];
                str1[(p + q) - (p / 2)] = str1[(p + q) - (p / 2) - 1];
                str1[(p + q) - (p / 2) - 1] = tp2;
                cout << str1 << endl;
            }
        }
    }
    return 0;
}