class Solution {
public:
    int search_iteration(int A[], int b,int e, int target)
    {
        if (e < b) return -1;
        if (b == e)
        {
            if (A[b] == target) return b;
            else return -1;
        }

        int mid = (b + e) >> 1;
        if (A[mid] == target) return mid;
        if (target > A[mid] && A[mid] < A[e])
        {
            return search_iteration(A, mid + 1, e,target);
        }
        else
        {
            int result = search_iteration(A, b, mid - 1, target);
            if (result == -1)
            {
                result = search_iteration(A, mid + 1, e,target);
            }
            return result;
        }

    }
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //for(int i = 0; i < n; ++i)
        //{
        //    if (A[i] == target) return i;
        //}
        return search_iteration(A,0,n-1,target);
    }
};