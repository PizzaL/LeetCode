#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int res = 0;
        for (size_t i=0; i<board.size(); ++i)
        {
            for (size_t j=0; j<board[i].size(); ++j)
            {
                if (board[i][j] == 'X')
                {
                    if ( (i==0 && j==0)
                      || (i==0 && j!=0 && board[i][j-1]!='X')
                      || (j==0 && i!=0 && board[i-1][j]!='X') 
                      || (i!=0 && j!=0 && board[i-1][j]!='X' && board[i][j-1]!='X') ) 
                        ++res;
                }
            }
        }
        return res;
    }
};

int main()
{
	Solution solution;
    vector<vector<char> > board;
    vector<char> row1;
    row1.push_back('.');
    row1.push_back('X');
    row1.push_back('X');
    row1.push_back('X');
    row1.push_back('X');
    row1.push_back('.');
    row1.push_back('X');
    row1.push_back('.'); 
    row1.push_back('X');
    board.push_back(row1);
	int res = solution.countBattleships(board);
	cout << res << endl;
	return 0;
}