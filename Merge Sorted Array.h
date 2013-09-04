class Solution {
public:
    void insert(int A[], int ai, int m, int B[], int bi)
    {
        for(int i = m; i > ai; --i)
        {
            A[i] = A[i-1];
        }
        A[ai] = B[bi];
    }
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ab = 0;
        int bb = 0;
        while(ab < m && bb < n)
        {
            if (A[ab] > B[bb])
            {
                insert(A,ab,m,B,bb);
                ab++;bb++;m++;
            }
            else
            {
                ab++;
            }
        }
        if (bb < n)
        {
            for(int i = 0; i < n - bb; ++i)
            {
                A[ab + i] = B[bb + i];
            }
        }
    }
};