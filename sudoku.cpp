#include <bits/stdc++.h>
using namespace std;

class Sudoku
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        if (solve(board) == false)
        {
            cout << "Sudoku is not possible";
        }
    }
    //-----------------------------------------------------------------------------
    bool solve(vector<vector<char>> &board)
    {
        int n = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isSafe(i, j, board, c))
                        {
                            board[i][j] = c;
                            if (solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    //-----------------------------------------------------------------------------
    bool isSafe(int i, int j, vector<vector<char>> board, char c)
    {
        for (int x = 0; x < board.size(); x++)
        {
            // column check
            if (board[i][x] == c)
            {
                return false;
            }
            // row check
            if (board[x][j] == c)
            {
                return false;
            }
            // box check
            if (board[3 * (i / 3) + x / 3][3 * (j / 3) + x % 3] == c)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Sudoku solver;

    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    solver.solveSudoku(board);

    for (int i = 0; i < board.size(); i++)
    {
        /* code */
        if (i == 0)
        {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - ";
            cout << endl;
            cout << endl;
        }
        cout << "|   ";
        for (int j = 0; j < board[i].size(); j++)
        {

            if (j == 3 or j == 6)
                cout << "|   ";

            cout << board[i][j] << "   ";
        }
        cout << "|";
        cout << endl;
        if (i == 2 or i == 5)
        {
            cout << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - ";
            cout << endl;
        }

        cout << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - ";

    // cout << "Donee";
}