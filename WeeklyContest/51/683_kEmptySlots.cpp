#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        if (flowers.size() < 2)
        {
            return -1;
        }
        vector<bool> blooms;
        for (size_t i=0; i<=flowers.size(); ++i)
        {
            blooms.push_back(false);
        }
        blooms[flowers[0]]=blooms[flowers[1]]=true;
        if (abs(flowers[0]-flowers[1])-1 == k)
            return 2;
        for (size_t i=2; i<flowers.size(); ++i)
        {
            int pos = flowers[i];
            blooms[pos]=true;
            int start = pos-1;
            while (start>=0 && !blooms[start])
                --start;
            if (start>=0 && pos-start-1==k)
                return i+1;
            int end = pos+1;
            while (end<flowers.size() && !blooms[end])
            {
                ++end;
            }
            if (end<flowers.size() && end-pos-1 == k)
                return i+1;
        }
        return -1;
    }
};
      
int main()
{
    return 0;
}