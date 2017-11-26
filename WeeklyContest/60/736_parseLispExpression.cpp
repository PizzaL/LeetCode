#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    bool match(string& word)
    {
        cout << "match=" << word << endl;
        int left = 0, right = 0;
        for (auto ch:word)
        {
            if (ch == '(')
                ++left;
            if (ch == ')')
                ++right;
        }
        return left <= right;
    }

    string getElement(istream& sin)
    {
        string word;
        if (sin >> word)
        {
            if (word[0] == '(')
            {
                while ( !match(word) )
                {
                    string temp;
                    sin >> temp;
                    word+=" " + temp;
                }
            }
        }
        return word;
    }

    int getValue(const string& word, map<string, int> env)
    {
        int res = 0;
        if (isdigit(word[0]) || word[0]=='-')
        {
            istringstream sin(word);
            sin >> res;
        }
        else if (isalpha(word[0]))
        {
            auto pos = word.find(')');
            res= env[word.substr(0, pos)];
        }
        else 
            res= evaluate(word, env);
        cout << word << "=" << res << endl;
        return res;
    }

    int add(const string& expression, map<string, int> env)
    {
        cout << expression << endl;
        vector<int> vars;
        istringstream sin(expression);
        string cmd;
        sin >> cmd;
        for (size_t i=0; i<2; ++i)
        {
            vars.push_back( getValue( getElement(sin), env) );
        }
        return vars[0]+vars[1];
    }

    int mult(const string& expression, const map<string, int>& env)
    {
        cout << expression << endl;
        vector<int> vars;
        istringstream sin(expression);
        string cmd;
        sin >> cmd;
        for (size_t i=0; i<2; ++i)
        {
            vars.push_back( getValue( getElement(sin), env) );
        }
        return vars[0]*vars[1];
    }

    int let(const string& expression, map<string, int>& env)
    {
        cout << expression << endl;
        istringstream sin(expression);
        string var;
        sin >> var;     // cmd (let
        vector<string> elements;
        var = getElement(sin);
        cout << "var=";
        while (!var.empty())
        {
                        cout << " " << var;
            elements.push_back(var);
            var=getElement(sin);
        }
        cout << endl;
        for (size_t i=0; i<elements.size()-1; i+=2)
        {
            env[elements[i]] = getValue(elements[i+1], env);
        }
        return getValue(elements[elements.size()-1], env);
    }

    int evaluate(const string& expression, map<string, int> env) {
        if (expression.empty())
            return 0;
        if (expression.substr(0, 4) == "(add")
        {
            return add(expression, env);
        }
        else if (expression.substr(0, 4) == "(let")
        {
            return let(expression, env);
        }
        else if (expression.substr(0,5) == "(mult")
        {
            return mult(expression, env);
        }
        return 0;
    }

    int evaluate(string expression) {
        map<string, int> env;
        return evaluate(expression, env);
    }
};

int main()
{
    Solution solution;
    cout << solution.evaluate("(let x 7 -12)");
    return 0;
}