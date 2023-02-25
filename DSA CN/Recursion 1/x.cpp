#include<iostream>
using namespace std;

int main() {
    // int x = 1;
    // x = ++x + ++x + ++x;
    // int x = 10;
    // x += (x++) + (++x);
    // cout << x;
    // if (x = 1)
    // {
    //     cout << "TRUE";
    // } else {
    //     cout << "FALSE";
    // }
    // int i = 1;
    // for (; i < 10; i = i / i)
    // {
    //     cout << i;
    // }
    char val = 1;
    if (val-- == 0)
    {
        cout << "TR";
    } else {
        cout << "Fa";
    }


    return 0;
}