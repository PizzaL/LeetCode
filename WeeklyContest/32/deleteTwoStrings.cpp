#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int res[500+5][500+5] = {0};
        if (word1.size() == 0)
            return word2.size();
        if (word2.size() == 0)
            return word1.size();
        for (size_t i=0; i<= word1.size(); ++i)
            res[i][0]=i;
        for (size_t i=0; i<= word2.size(); ++i)
            res[0][i]=i;
        for (int i=1; i<= word1.size(); ++i)
            for (int j=1; j<=word2.size(); ++j)
            {
                if (word1[i-1] == word2[j-1])
                {
                    res[i][j] = res[i-1][j-1];
                    cout << i << "," << j << "=i-1, j-1 " 
                         << res[i][j]<< endl; 
                }
                else 
                {
                    res[i][j] = res[i-1][j-1]+2;
                    cout << i << "," << j << "=i-1, j-1 " 
                         << res[i][j]<< endl; 
                }

                res[i][j] = min(res[i][j], res[i-1][j] + 1);
                    cout << i << "," << j << "=i-1, j " 
                         << res[i][j]<< endl; 
            
               res[i][j] = min(res[i][j], res[i][j-1] + 1);
                    cout << i << "," << j << "=i, j-1 " 
                         << res[i][j]<< endl; 
            }
        return res[word1.size()][word2.size()];
    }
};

int main()
{
    string word1("horse");
    string word2("ros");

    Solution solution;
    cout << solution.minDistance(word1, word2);
    return 0;
}