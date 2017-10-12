#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MapSum {
public:
    struct Node {
        int val;
        Node* next[26];
        Node(int val)
            : val(val)
        {
            for (size_t i=0; i<26; ++i)
                next[i]=NULL;
        }
    };
    MapSum() {
        root = NULL;
    }
    
    void insert(string key, int val) {
        if (!root)
            root = new Node(0);
        Node* currNode = root;
        for (size_t i=0; i<key.length(); ++i)
        {
            int idx = key[i]-'a';
            if (!currNode->next[idx])
                currNode->next[idx] = new Node(0);
            currNode = currNode->next[idx];
        }
        currNode->val = val;
    }
    
    int calSum(Node* rootNode)
    {
        if (!rootNode)
            return 0;
        int res = rootNode->val;
        for (size_t i=0; i<26; ++i)
        {
            res+=calSum(rootNode->next[i]);
        }
        return res;
    }

    int sum(string prefix) {
        Node* currNode = root;
        for (size_t i=0; i<prefix.length(); ++i)
        {
            if (!currNode)
                return 0;
            int idx = prefix[i]-'a';
            currNode=currNode->next[idx];
        }
        return calSum(currNode);
    }
private:
    Node* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
int main()
{
	MapSum mapSum;
	return 0;
}