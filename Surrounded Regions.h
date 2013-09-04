#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<char>> &board,int x,int y)
    {
        vector<char> &row = board[x];

        if (row[y] == 'X')
        {
            return true;
        }
        if (x == board.size() - 1 || x == 0 || y == 0 || y == row.size() - 1) return false;       
        row[y] = 'P';

        vector<char> &uprow = board[x-1];
        vector<char> &downrow = board[x+1];
        bool isSurround = true;
        if (row[y-1] == 'O') isSurround &= check(board,x,y-1);
        if (row[y+1] == 'O') isSurround &= check(board,x,y+1);
        if (uprow[y] == 'O') isSurround &= check(board,x-1,y);
        if (downrow[y] == 'O') isSurround &= check(board,x+1,y);
        return isSurround;
    }
    void fill(vector<vector<char>> &board,char c) {
        for(int i = 1; i < (int)board.size() - 1; ++i)
        {
            vector<char> &row = board[i];
            for(int j = 1; j < (int)row.size() - 1; ++j)
            {
                if (row[j] == 'P')
                {
                    row[j] = c;
                }
            }
        }
    }
    void unfill(vector<vector<char>> &board,char c)
    {
        for(int i = 1; i < (int)board.size() - 1; ++i)
        {
            vector<char> &row = board[i];
            for(int j = 1; j < (int)row.size() - 1; ++j)
            {
                if (row[j] == c)
                {
                    row[j] = 'O';
                }
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 1; i < (int)board.size() - 1; ++i)
        {
            vector<char> &row = board[i];
            for(int j = 1; j < (int)row.size() - 1; ++j)
            {
                if (row[j] == 'O')
                {
                    if (check(board,i,j))
                        fill(board,'X');
                    else
                        fill(board,'Z');
                }
            }
        }
        unfill(board,'Z');
    }
};