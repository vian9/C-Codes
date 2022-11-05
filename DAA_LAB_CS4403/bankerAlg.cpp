#include<iostream>
using namespace std;

void bankerAlgo(int** allocation, int** max, int* available, int p, int r) {
    int x, y, z;
    int g[p], answer[p], ind = 0;
    for (z = 0; z < p; z++) {
        g[z] = 0;
    }
    int req[p][r];
    for (x = 0; x < p; x++) {
        for (y = 0; y < r; y++)
            req[x][y] = max[x][y] - allocation[x][y];
    }
    int a = 0;
    for (z = 0; z < 5; z++) {
        for (x = 0; x < p; x++) {
            if (g[x] == 0) {

                int alert = 0;
                for (y = 0; y < r; y++) {
                    if (req[x][y] > available[y]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    answer[ind++] = x;
                    for (a = 0; a < r; a++)
                        available[a] += allocation[x][a];
                    g[x] = 1;
                }
            }
        }
    }

    int alert = 1;

    for (int i = 0;i < p;i++)
    {
        if (f[i] == 0)
        {
            alert = 0;
            cout << "The sequence is not Safe.";
            break;
        }
    }

    if (alert == 1)
    {
        cout << "The Safe Sequence is : " << endl;
        for (x = 0; x < p - 1; x++)
            cout << " P" << answer[x] << " ->";
        cout << " P" << answer[p - 1] << endl;
    }
}

int main() {
    int p;
    cout << "Enter the Total number of Process: " << endl;
    cin >> p;
    int r;
    cout << "Enter the Total number of Resources: " << endl;
    cin >> r;
    int** allocation = new int* [p];
    int** max = new int* [p];
    cout << "Enter the Allocation Value in resources: " << endl;
    for (int i = 0; i < p; i++)
    {
        allocation[i] = new int[r];
        for (int j = 0; j < r; j++)
        {
            cin >> allocation[i][j];
        }

    }

    cout << "Enter the Max Value in resources: " << endl;
    for (int i = 0; i < p; i++)
    {
        max[i] = new int[r];
        for (int j = 0; j < r; j++)
        {
            cin >> max[i][j];
        }

    }
    int* available = new int[r];
    cout << "Enter the Available Value in resources: " << endl;
    for (int i = 0; i < r; i++)
    {
        cin >> available[i];
    }
    bankerAlgo(allocation, max, available, p, r);

    return 0;
}