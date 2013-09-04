#include <vector>

using namespace std;

class Solution {
public:

    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> stVec;
        vector<int> enVec;
        stVec.resize(prices.size(),0);
        enVec.resize(prices.size(),0);
        for(unsigned int i = 1; i < prices.size(); ++i)
        {
            int profit = prices[i] - prices[i-1];
            if (profit + stVec[i-1] > 0)
            {
                stVec[i] = stVec[i-1] + profit;
            }
        }
        for(int i = prices.size() - 1; i > 0; --i)
        {
            int profit = prices[i] - prices[i-1];
            if (profit + enVec[i] > 0)
            {
                enVec[i - 1] = enVec[i] + profit;
            }
        }
        for(unsigned int i = 1; i < prices.size(); ++i)
        {
            if (stVec[i] < stVec[i - 1]) stVec[i] = stVec[i - 1];
        }
        for(int i = prices.size() - 1; i > 0; --i)
        {
            if (enVec[i - 1] < enVec[i]) enVec[i - 1] = enVec[i];
        }
        int maxc = 0;
        for(unsigned int i = 0; i < prices.size(); ++i)
        {
            if (stVec[i] + enVec[i] > maxc)
            {
                maxc = stVec[i] + enVec[i];
            }
        }
        return maxc;
    }
};