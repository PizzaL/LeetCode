#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    typedef vector<string>::iterator SVI;
    void eraseMulti(SVI& row, size_t start, vector<string>& source)
    {
        auto endPos = row->find("*/",start);
        if (endPos != string::npos)
        {   
            if (endPos != start+1) {  // */
                row->erase(start, endPos-start+2);
                if (row->empty())
                    source.erase(row);
                return ;
            }
            else 
            {
                endPos = row->find("*/", endPos+2);
                if (endPos != string::npos)
                {
                    row->erase(start, endPos-start+2);
                    if (row->empty())
                        source.erase(row);
                    return;
                }
            }
        } 
        
        row->erase(start);
        auto comment = next(row);
        for (; comment!=source.end();)
        {
            endPos = comment->find("*/");
            if (endPos != string::npos)
            {   // */
                comment->erase(0, endPos+2);
                break;
            } else {
                source.erase(comment);
            }
        }
        *row = *row+*comment;
        source.erase(comment);
        
        if (row->empty())
            source.erase(row);
    }

    vector<string> removeComments(vector<string>& source) {
        for (auto row=source.begin(); row!=source.end();)
        {
            auto posOneLine = row->find("//");
            auto posMultiLine = row->find("/*");
            if (posOneLine != string::npos && posMultiLine != string::npos)
            {   //  // & /*
                if (posOneLine < posMultiLine)
                {   // //
                    row->erase(posOneLine);
                    if (row->empty())
                        source.erase(row);
                } else
                {   // /*
                    eraseMulti(row, posMultiLine, source);
                }
            } else if (posOneLine != string::npos)
            {   //  //
                row->erase(posOneLine);
                if (row->empty())
                    source.erase(row);
            } else if (posMultiLine != string::npos)
            {   //  /*
                eraseMulti(row, posMultiLine, source);
            } else 
            {   // code
                ++row;
            }
        }
        return source;
    }
};
      
int main()
{
    vector<string> source;
    source.push_back("/*/d//*//*d//*/*/cbcedae/*/b//*/*//*/*//eae/*/a*///*///*ca//*ab//*e/*/eebea/*/");
    source.push_back("blank");
    source.push_back("d//e/*/f");
    Solution solution;
    solution.removeComments(source);
    return 0;
}