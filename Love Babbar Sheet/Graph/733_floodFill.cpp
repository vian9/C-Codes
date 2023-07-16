// Link : https://leetcode.com/problems/flood-fill/
// Time Complexity : O()
// Approach-> Bfs Dfs tb krte h jb traversal krna ho and no need to explore all paths.....recursion ya dp tb lgata h tb explore all possibility krna hota h
// Isme hum agar initial color h pixel ka toh source ka 4 direction mein jakr color change krdenge....Isme dfs bfs koi bhi use kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// DFS
void dfs(int m, int n, vector<vector<int>> &image, int sr, int sc, int color, int initial, vector<vector<int>> &visited, vector<int> &d1, vector<int> &d2)
{
    // mark visited and set color for the pixel
    visited[sr][sc] = 1;
    image[sr][sc] = color;
    for (int i = 0; i < 4; i++)
    {
        // Now either you can move 1 to 3 and alag combination for row and col lgakr call krdo
        //  int row = sr + d[i];
        //  int col = sc + d[i];
        //  if ((row >= 0 && row < m) && (!visited[row][sc] && image[row][sc] == initial))
        //  {
        //      dfs(m, n, image, row, sc, color, initial, visited, d);
        //  }
        //  if ((col >= 0 && col < n) && (!visited[sr][col] && image[sr][col] == initial))
        //  {
        //      dfs(m, n, image, sr, col, color, initial, visited, d);
        //  }

        // Aur row and col ko move krdo alag alag and usme call
        int row = sr + d1[i];
        int col = sc + d2[i];
        // Ab agar not visited h and initial jaisa color to call
        if ((row >= 0 && row < m && col >= 0 && col < n) && (!visited[row][col] && image[row][col] == initial))
        {
            dfs(m, n, image, row, col, color, initial, visited, d1, d2);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();
    // vector<int> d = {-1, 0, 1};
    // Ye dekho upar ka source row se ek cycle mein kaise value change horha h...similar for col
    vector<int> d1 = {-1, 0, 1, 0};
    vector<int> d2 = {0, -1, 0, 1};
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int initial = image[sr][sc];
    dfs(m, n, image, sr, sc, color, initial, visited, d1, d2);
    return image;
}

int main()
{

    return 0;
}