#include <vector>

using namespace std;

class Solution {
public:
    int getRect(vector<int> &height,int n)
    {
        if (n >= height.size()) return 0;
        int count = height[n];
        int result = count;
        for(int i = n + 1; i < height.size(); ++i)
        {
            if (height[i] >= count) result += count;
            else break;
        }
        return result;
    }
    int getRect_back(vector<int> &height,int n)
    {
        if (n <= 0) return 0;
        int count = height[n];
        int result = count;
        for(int i = n - 1; i >= 0; --i)
        {
            if (height[i] >= count) result += count;
            else break;
        }
        return result - height[n];
    }
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxc = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            int r = getRect(height,i) + getRect_back(height,i);
            if (r > maxc) maxc = r;
        }
        return maxc;
    }
};