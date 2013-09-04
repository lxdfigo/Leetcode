#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> & set, vector<vector<int> >& sets)
    {
        for(int i = 0; i < sets.size(); ++i)
        {
            if (sets[i].size() != set.size()) continue;
            bool sign = false;
            for(int j = 0; j < set.size(); ++i)
            {
                if (set[j] != sets[i][j]) 
                {
                    sign = true; break;
                }
            }
            if (sign == false) return false;
        }
        return true;
    }
    void insertSet(const vector<int> &S, int offset, vector<int> & set, vector<vector<int> >& sets)
    {
        for(int i = offset; i < S.size(); ++i)
        {
            set.push_back(S[i]);
            if (check(set,sets)) 
            {
                sets.push_back(set);
                insertSet(S,i+1,set,sets);
            }
            set.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0; i < S.size() - 1; ++i)
        {
            for(int j = i + 1; j < S.size();++j)
            {
                if (S[i] > S[j])
                {
                    int tmp = S[i]; S[i] = S[j]; S[j] = tmp;
                }
            }
        }
        vector<vector<int> > sets;
        vector<int> set;
        sets.push_back(set);
        insertSet(S,0,set,sets);
        return sets;
    }
};