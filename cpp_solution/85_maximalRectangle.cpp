#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int calMaxRect(vector<vector<char> >& widthMatrix, int row, int head, int tail)
    {
        if (head <= tail)
            return 0;
        int res = tail-head;
        for (int i = row; i!=0; --i)
        {
            int start = head, currLength=0;
            for (int j=head; j<right; ++j)

        }
    }

    int maximalRectangle(vector<vector<char> >& matrix) {
        vector<vector<int> > widthMatrix;
        for (size_t i=0; i<matrix.size(); ++i)
        {
            vector<char>& currRow = matrix[i];
            vector<int> width;
            width.reserve(currRow.size());
            width[0] = (currRow[0] == '1');
            for (size_t j = 1; j<currRow.size(); ++j)
            {
                if (currRow[j] == '1')
                    width[j] = width[j] +1;
                else
                    width[j] = 0;
            }
            widthMatrix.push_back(width);
        }
        int res = 0;;
        for (size_t i=0; i<matrix.size(); ++i)
        {
            vector<char>& currRow = matrix[i];
            int head = 0, tail = 0;
            while ( tail < currRow.size() )
            {
                if (currRow[tail] == '0')
                {
                    res = max( res, calMaxRect(widthMatrix, i, head, tail) );
                    head = tail+1;
                }
                ++tail;
            }
            res =  max(res, calMaxRect(widthMatrix, i, head, tail) );
        }
        return res;
    }
};

int main()
{
	Solution solution;
	vector<vector<int> > matrix;
	cout << solution.maximalRectangle(matrix) << endl;
	return 0;
}