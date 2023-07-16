// Link : https://leetcode.com/problems/sudoku-solver/submissions/
// Time Complexity : O()
// Approach-> Phle ek row and col k liye val 1 to 9 check kro and if valid then put kro and pura col fill krne tk wait kro tb fill hoga otherwise pop
// Similar to N-queen....bs check how to valid 3*3 submatrix

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(vector<vector<char>> &board, int row, int col, char val, int n)
{
    // 0 to 8 tk loop chalao and usse m row and col check kro
    for (int i = 0; i < 9; i++)
    {
        // Isme row check horha
        if (board[row][i] == val)
            return false;
        // Isme col check horha
        if (board[i][col] == val)
            return false;
        // Isme wo row and col jo sub matrix 3 * 3 mein lie krrha h wo check horha h
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
        // row = 5 , col = 3....to (row/3 * 3) will give us the definite row or start row and it's a fixed val waise hi for col
        // now +i/3 will move only when it gets more than a multiple of 3 but i%3 will move always for every i
        // that tells use for a row col will move 3 times and similary row will change and col again 3 times
    }
    return true;
}

// Isme col ko pass krdiya recursion m and phle saara row fill krrhe h for a col
bool solveBoard(vector<vector<char>> &board, int n, int col)
{

    // Since ek hi ans lana h to jaise hi col exceed ho return krdo
    if (col >= n)
    {
        return true;
    }
    // Row iterate krrhe
    for (int row = 0; row < board.size(); row++)
    {
        // If blank
        if (board[row][col] == '.')
        {
            // 1 to 9 char dalkr check krenge
            for (char val = '1'; val <= '9'; val++)
            {
                // Ab usse valid h ya nhi usse pos pr dekho
                if (isValid(board, row, col, val, n))
                {
                    // ek hi possibility generate krne h so no pop out
                    board[row][col] = val;
                    // Ab wo val dalkr next ko call krdo and agar true return hota h pura fill hone k baad to thik wrna pop krdo
                    if (solveBoard(board, n, col) == true)
                        return true;
                    else
                        board[row][col] = '.';
                }
            }
            return false;
        }
    }
    // Ek Col bhar gya next ko call krdo
    return solveBoard(board, n, col + 1);
}

// Isme loop m row and Col chalrha h
// bool solveBoard(vector<vector<char>> &board, int n)
// {

//     for (int row = 0; row < board.size(); row++)
//     {
//         for (int col = 0; col < board[0].size(); col++)
//         {
//             if (board[row][col] == '.')
//             {
//                 for (char val = '1'; val <= '9'; val++)
//                 {
//                     if (isValid(board, row, col, val, n))
//                     {
//                         // ek hi possibility generate krne h so no pop out
//                         board[row][col] = val;
//                         if (solveBoard(board, n) == true)
//                             return true;
//                         else
//                             board[row][col] = '.';
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

void solveSudoku(vector<vector<char>> &board)
{
    solveBoard(board, 9, 0);
}

int main()
{

    return 0;
}