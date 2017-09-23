#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (size_t i=0; i<ransomNote.size(); ++i)
        {
            size_t pos = magazine.find(ransomNote[i]);
            if ( pos == string::npos)
                return false;
            else 
                magazine[pos]=' ';
        }
        return true;
    }
};

int main()
{
	Solution solution;
	return 0;
}