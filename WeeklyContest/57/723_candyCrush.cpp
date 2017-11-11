#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    void print(vector<vector<int> >& board)
    {
        for (auto& row:board)
        {
            for (auto& num:row)
                cout << num << " ";
            cout << endl;
        }
    }
    bool crush(vector<vector<int> >& board)
    {
        bool flag = false;
        vector<vector<int> > newBoard = board;
        // row
        for (size_t i=0; i<newBoard.size(); ++i)
        {
            vector<int>& currRow = newBoard[i];
            int idx = 0; 
            while (idx < currRow.size() )
            {
                if (currRow[idx])
                {
                    int start = idx;
                    const int val = board[i][idx];
                    while (idx < currRow.size() && currRow[idx] == val)
                    {
                        ++idx;
                    }
                    if (idx-start>=3)
                    {
                        flag = true;
                        for (size_t j=start; j<idx; ++j)
                            currRow[j]=0;
                    }
                } else
                    ++idx;
            }
        }
        // col
        for (size_t i=0; i<newBoard[0].size(); ++i)
        {
            int idx = 0; 
            while (idx < newBoard.size() )
            {
                if (board[idx][i])
                {
                    int start = idx;
                    const int val = board[idx][i];
                    while (idx < newBoard.size() && board[idx][i] == val)
                    {
                        ++idx;
                    }
                    if (idx-start>=3)
                    {
                        flag = true;
                        for (size_t j=start; j<idx; ++j)
                            newBoard[j][i]=0;
                    }
                } else
                    ++idx;
            }
        }
        board = newBoard;
        return flag;
    }
    void cleanBoard(vector<vector<int> >& board)
    {
        for (size_t i=0; i<board[0].size(); ++i)
        {
            int idx = board.size()-1;
            for (int j=board.size()-1; j>=0;)
            {
                while (j>=0 && board[j][i] == 0)
                {
                    --j;
                }
                if (j>=0)
                {
                    board[idx][i] = board[j][i];
                    --idx;
                    --j;
                }
            }
            for (int j=0;j<=idx; ++j)
                board[j][i] = 0;
        }
    }

    vector<vector<int> > candyCrush(vector<vector<int> >& board) {
        while (crush(board))
        {
            cleanBoard(board);
            print(board);
            cout << endl;
        }
        return board;
    }
};
      
int main()
{
    vector<vector<int> > board;
    vector<int> row_4 = {110,5,112,113,114};
    vector<int> row_3 = {210,211,5,213,214};
    vector<int> row_2 = {310,311,3,313,314};
    vector<int> row_1 = {410,411,412,5,414};
    vector<int> row = {5,1,512,3,3};
    vector<int> row0 = {610,4,1,613,614};
    vector<int> row1 = {710,1,2,713,714};
    vector<int> row2 = {810,1,2,1,1};
    vector<int> row3 = {1,1,2,2,2};
    vector<int> row4 = {4,1,4,4,1014};
    board.push_back(row_4);
    board.push_back(row_3);
    board.push_back(row_2);
    board.push_back(row_1);
    board.push_back(row);
    board.push_back(row0);
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    Solution solution;
    solution.candyCrush(board);

    return 0;
}