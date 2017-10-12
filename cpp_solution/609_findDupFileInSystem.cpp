#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        map<string, vector<string> > mapping;
        for (size_t i=0; i<paths.size(); ++i)
        {
            istringstream sin(paths[i]);
            string dir, file;
            sin >> dir;
            while (sin >> file)
            {
                size_t pos = file.find('(');
                string filename = file.substr(0, pos);
                string content = file.substr(pos+1, file.length()-pos-2);
                filename = dir + "/" + filename;
                if ( mapping.find(content) == mapping.end() )
                {
                    vector<string> files;
                    files.push_back(filename);
                    mapping[content] = files;
                } else
                {
                    mapping[content].push_back(filename);
                }
            }
        }
        vector<vector<string> > res;
        typedef map<string, vector<string> >::iterator SVIT;
        for (SVIT it = mapping.begin(); it != mapping.end(); ++it)
        {
            if (it->second.size() > 1)
            {
                res.push_back(it->second);
            }
        }
        return res;
    }
};

int main()
{
	Solution solution;

	return 0;
}