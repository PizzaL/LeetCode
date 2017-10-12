#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPut(int board[], int n, int i, int j)
    {
        if ( i == 0)
            return true;
        for (int k=0; k<i; ++k)
        {
            if (board[k] == j || abs(board[k]-j) == abs(k-i) )
                return false;
        }
        return true;
    }

    int generateBoard(int board[], int n, int i, bool usage[])
    {
        if (i == n)
            return 1;
        int res = 0;
        for (size_t j=0; j<n; ++j)
        {   
            if (usage[j] && canPut(board, n, i, j))
            {
                board[i] = j;
                usage[j] = false;
                //cout << i << ", " << j << endl;
                res += generateBoard(board, n, i+1, usage);
                usage[j] = true;
            }
        }
        return res;
    }

    int totalNQueens(int n) {
        bool usage[n];
        for (size_t i=0; i<n; ++i)
            usage[i] = true;
        int board[n];
        return generateBoard(board, n, 0, usage);
    }
};

int main()
{
	Solution solution;
    cout << solution.totalNQueens(8) << endl;
	return 0;
}