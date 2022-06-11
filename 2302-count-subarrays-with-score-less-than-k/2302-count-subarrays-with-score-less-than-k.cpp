 /*[j-i+1] : window size */
/* The score of the subarray in the window is sum * (i - j + 1). We move the left side of the window, decreasing sum, if that score is equal or greater than k */

class Solution {
public:
    long long countSubarrays(vector<int>& A, long long k) {
        long long res = 0, cur = 0;
        for (int j = 0, i = 0; j < A.size(); ++j) {
            cur += A[j];
            while (cur * (j - i + 1) >= k)
                cur -= A[i++];
            res += j - i + 1;
        }
        return res;
    }
}; 