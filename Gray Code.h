#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> & vec,int num)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] == num) return false;
        }
        return true;
    }
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec;
        vec.push_back(0);
        int sign = true;
        while(sign)
        {
            sign = false;
            for(int i = 0; i < n; ++i)
            {
                int tmp =  (1 << i);
                if ((vec[vec.size() - 1] & tmp) != 0)
                {
                    if (check(vec, vec[vec.size() - 1] - tmp))
                    {
                        vec.push_back(vec[vec.size() - 1] - tmp);
                        sign = true;
                        break;
                    }
                }
                else 
                {
                    if (check(vec, vec[vec.size() - 1] + tmp))
                    {
                        vec.push_back(vec[vec.size() - 1] + tmp);
                        sign = true;
                        break;
                    }
                }
            }
        }
        return vec;
    }
};