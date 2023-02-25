#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
    int n = 0;
    cout << "series of asterisk";
    cin >> n;
    int i;
    for (i = 1;i <= n;i++)
    {
        int j;
        for (j = 1;j <= i;j++) {
            printf(" * ");
        }
        printf("\n");
    }
    return 0;
}