#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class RandomizedCollection {
public:

    unordered_map<int, vector<int> > valPosMap;
    vector<pair<int, int> > valList;

    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (valPosMap.find(val)!=valPosMap.end())
        {
            valList.push_back(pair<int, int>(val, valPosMap[val].size()));
            valPosMap[val].push_back(valList.size()-1);
            return false;
        }
        else
        {
            valList.push_back(pair<int, int>(val, 0));
            vector<int> list={int(valList.size()-1)};
            valPosMap[val]=list;
            return true;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (valPosMap.find(val)!=valPosMap.end())
        {
            vector<int>& list=valPosMap[val];
            int pos = list[list.size()-1];
            pair<int, int>& lastItem = valList[valList.size()-1];
            valPosMap[lastItem.first][lastItem.second] = pos;
            valList[pos]=valList[valList.size()-1];
            valList.erase(valList.end()-1);
            list.erase(list.end()-1);
            if (list.empty())
            {
                valPosMap.erase(val);
            }
            return true;
        }
        return false;
    }
    
    int genInt(int val)
    {
        return int(1.0*rand()/RAND_MAX*val);
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return valList[genInt(valList.size())].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    RandomizedCollection rand;
    for (size_t i=0; i<10; ++i)
        cout << rand.genInt(30) << endl;
	return 0;
}