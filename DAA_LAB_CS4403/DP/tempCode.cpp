#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& curr, int row, int col) {
    for (int i = 0; i <= row - 1; i++) {
        if (curr[i] - 1 == col || abs(curr[i] - 1 - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> helper(int row, int n, vector<int>& temp, vector<vector<int>>& ans) {

    for (int col = 0; col < n; col++) {
        if (isSafe(temp, row, col)) {
            temp[row] = col + 1;
            if (row == n - 1) {
                ans.push_back(temp);
            } else {
                helper(row + 1, n, temp, ans);
            }
        }
    }
    return ans;
}

vector<vector<int>> nQueen(int n) {
    vector<int> temp(n, -1);
    vector<vector<int>> ans;
    return helper(0, n, temp, ans);
}

int main() {
    int n;
    cout << "Enter the Size: " << endl;
    cin >> n;
    vector<vector<int>> ans = nQueen(n);
    for (vector<int> v : ans) {
        for (int it : v) {
            cout << it << " ";
        } cout << endl;
    }

    return 0;
}