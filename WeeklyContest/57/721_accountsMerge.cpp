#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
#include <set>

using namespace std;

class Solution {
public:
    bool merge(vector<string>& oldAccount, vector<string>& account)
    {
        if (oldAccount[0] == account[0])
        {
            set<string> oldSet(next(oldAccount.begin()), oldAccount.end());
            set<string> accountSet(next(account.begin()), account.end());
            set<string> newSet(oldSet.begin(), oldSet.end());
            newSet.insert(accountSet.begin(), accountSet.end());
            if (newSet.size() < oldSet.size() + accountSet.size())
            {
                vector<string> newAccount(newSet.begin(), newSet.end());
                newAccount.insert(newAccount.begin(), oldAccount[0]);
                oldAccount = newAccount;
                return true;
            }
        } 
        return false;
    }

    void cleanup(vector<vector<string> >& res, vector<vector<string> >::iterator& account)
    {
        for (auto oldAcc=res.begin(); oldAcc!=res.end(); ++oldAcc)
        {
            if (oldAcc != account)
            {
                if (merge(*oldAcc, *account))
                {
                    res.erase(account);
                    cleanup(res, oldAcc);
                    return ;
                }
            }

        }
    }

    void insert(vector<vector<string> >& res, vector<string>& account)
    {
        for (auto oldAccount=res.begin(); oldAccount!=res.end(); ++oldAccount)
        {
            if (merge(*oldAccount, account))
            {
                cleanup(res, oldAccount);
                return;
            }
        }
        set<string> newSet(next(account.begin()), account.end());
        vector<string> newAccount(newSet.begin(), newSet.end());
        newAccount.insert(newAccount.begin(), account[0]);
        res.push_back(newAccount);
    }

    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
        vector<vector<string> > res;
        for (auto& account:accounts)
        {
            insert(res, account);
        }
        return res;
    }
};
      
int main()
{
    return 0;
}