#include<iostream>
using namespace std;

bool place(int k, int i, int* x) {
    for (int j = 1; j < k - 1; j++)
    {
        if ((x[j] == i) || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }


    }
    return true;

}

void nQueens(int k, int n) {
    int* x = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (place(k, i, x))
        {
            x[k] = i;
            if (k == n)
            {
                cout << "Position of queens are: " << endl;
                for (int j = 0; j < n; j++)
                {
                    cout << x[j] << " ";
                }
                break;
            }
        } else {
            nQueens(k + 1, n);
        }
    }

}


int main() {
    int n;
    cout << "Enter no. of queens: " << endl;
    cin >> n;
    nQueens(0, n);

    return 0;
}