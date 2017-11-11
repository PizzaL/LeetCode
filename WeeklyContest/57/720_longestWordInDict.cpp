#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;



class Solution {
public:
    struct Node{
        char ch;
        Node* next[26];
        bool isWord;
        Node (char ch) : ch(ch), isWord(false)
        {
            for (size_t i=0;i<26; ++i)
                next[i]=NULL;
        }
    };

    void insert(Node* root, string& word, int pos)
    {
        if (pos == word.length())
            return ;
        int idx = word[pos]-'a';
        if (!root->next[idx])
        {
            root->next[idx] = new Node(word[pos]);
        }
        if (pos == word.length()-1)
            root->next[idx]->isWord = true;
        else
            insert(root->next[idx], word, pos+1);
    }

    string findWord(Node* root, const string& curr)
    {
        if (!root)
        {
            return string();
        }
        string res;
        for (size_t i=0; i<26; ++i)
        {
            if (root->next[i] && root->next[i]->isWord)
            {
                string r = findWord(root, curr+root->next[i]->ch);
                if (r.length()>res.length())
                    res = r;
            }
        }
        return res;
    }

    string longestWord(vector<string>& words) {
        Node* root = new Node('a');
        for (auto word:words)
        insert(root, word, 0);
        return findWord(root, "");
    }
};
      
int main()
{
    return 0;
}