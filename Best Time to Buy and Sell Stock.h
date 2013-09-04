#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2) return 0;

        int lastvalue = prices[0];
        int maxc = 0;
        prices[0] = 0;
        for(unsigned int i = 1; i < prices.size(); ++i)
        {
            int profit = prices[i] - lastvalue;
            lastvalue = prices[i];
            if (profit + prices[i-1] > 0)
            {
                prices[i] = prices[i-1] + profit;
                if (prices[i] > maxc) maxc = prices[i];
            }
            else
            {
                prices[i] = 0;
            }
        }
        return maxc;
    }
};