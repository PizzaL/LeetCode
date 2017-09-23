#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    struct Function {
        int funcId, time;
        Function(int funcId, int time): funcId(funcId), time(time)
        {}
    };
    struct OtherTime {
        int funcId, time;
        OtherTime(int funcId, int time): funcId(funcId), time(time)
        {}
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Function> timeline;
        stack<OtherTime> otherTime;
        vector<int> funcTime;
        funcTime.reserve(n);
        for (size_t i=0; i<n; ++i)
            funcTime[i] = 0;
        for (size_t i=0; i<logs.size(); ++i)
        {
            istringstream sin(logs[i]);
            int funcId;
            string restStr;
            sin >> funcId >> restStr;
            string keyWord = restStr.find(':');
            cout << funcId << " " << keyWord << time << endl;
            if (keyWord == "start:")
            {
                timeline.push(Function(funcId, time));
            } else
            {
                if (timeline.empty())
                {
                    cout << "ERROR" << endl;
                    break;
                }
                int startTime = timeline.top().time;
                timeline.pop();
                if (!otherTime.empty() && otherTime.top().funcId == funcId)
                {
                    funcTime[funcId] += time - startTime + otherTime.top().time;
                    otherTime.pop();
                } else
                {
                    funcTime[funcId] += time - startTime;
                    if ( timeline.empty() )
                    {
                        cout << i << endl;
                        break;
                    }
                    if ( !otherTime.empty()
                      && otherTime.top().funcId == timeline.top().funcId)
                    {
                        otherTime.top().time += time - startTime;
                    } else
                    {
                        otherTime.push(OtherTime(timeline.top().funcId, time - startTime));
                    }
                }
            }
        }
        return funcTime;
    }
};
int main()
{
	vector<string> logs;
    logs.push_back("0:start:0");
    logs.push_back("1:start:2");
    logs.push_back("1:end:5");
    logs.push_back("0:end:6");

	Solution solution;
	solution.exclusiveTime(2, logs);
    return 0;
}