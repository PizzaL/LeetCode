#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        char ch;
        Node* next[26];
        bool leaf;
        Node(char ch) : ch(ch), leaf(false)
        {
            for (size_t i=0; i<26; ++i)
                next[i]=NULL;
        }
    };
    MagicDictionary() : root(new Node(' ')) {
    }
    
    void insert(Node* root, const string& word, int pos)
    {
        if (!root->next[word[pos]-'a'])
        {
            root->next[word[pos]-'a'] = new Node(word[pos]);
        }
        if (pos == word.length()-1)
        {
            root->next[word[pos]-'a']->leaf = true;
        }
        else
            insert(root->next[word[pos]-'a'], word, pos+1);
    }
    /** Build a dictionary through a list of words */
    void buildDict(const vector<string>& dict) {
        for (size_t i=0; i<dict.size(); ++i)
        {
            string word = dict[i];
            if (!word.empty())
                insert(root, word, 0);
        }
    }
    
    bool find(Node* root, const string& word, int pos, int fuzzy)
    {
        for (size_t i=0; i<26; ++i)
        {
            if (root->next[i])
            {
                cout << root->next[i]->ch << " " << fuzzy << root->next[i]->leaf<< endl;
                if ( root->next[i]->ch == word[pos])
                {
                    if (pos == word.length()-1)
                    {
                        if (fuzzy ==0 && root->next[i]->leaf)
                            return true;
                    } else if (find(root->next[i], word, pos+1, fuzzy) )
                        return true;
                }
                else
                { 
                    if (pos == word.length()-1)
                    {
                        if (fuzzy ==1 && root->next[i]->leaf)
                            return true;
                    } else if (find(root->next[i], word, pos+1, fuzzy-1) )
                            return true;
                }
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string& word) {
        if (word.empty())
            return false;
         return find(root, word, 0, 1);
    }
private:
    Node* root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main()
{
	return 0;
}