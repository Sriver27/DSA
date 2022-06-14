// We can apply binary search using slightly different logic as well.

// Suppose you are given a sorted array with all elements occur twice. For eg. [1,1,2,2,5,5,7,7,8,8]. So, here we can see that the elements follow the condition - nums[0] == nums[1], nums[2] == nums[3],..., nums[2*k] == nums[2*k+1]. Now, if we insert an element somewhere in the array, the above relation wont be satisfied from that point of insertion. Eg. [1,1,2,2,4,5,5,7,7,8,8] the condition starts to fail from element 4, that is from point where single-occurence element is present.

// Thus, we can use this observation to apply binary-search to find the starting point from where the above condition starts to fail. This start point is the index of element occuring once. The binary search will be applied as follows -

/* Initialize the search space as [L, R] = [0, n-1] and repeat the following step till 
L <= R.*/

// Find the mid position and check if the above condition nums[2*k] == nums[2*k+1] is satisifed or not.
// For this, firstly we must ensure that mid is even. If mid is odd, decrease it by 1 to make it even.
// Then, we need to check if the condition is satisfied or not -

    // nums[mid] == nums[mid+1] : The condition is correctly satisfied till index           mid+1. So, the required element must occur somewhere on the right of mid+1. So do L     = mid+2.

    // nums[mid] != nums[mid+1] : The condition is not satisfied at this point. So, the     required element must either be nums[mid] or occur somewhere on the left of mid due     to which the relation is not satisfied. Mark nums[mid] as a potential answer and        search if condition is satisfied to the left of mid by doing R = mid-1

// Finally, we return the ans which was marked as potential answer during the binary search.




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = size(nums), L = 0, R = n-1, mid, ans;
        while(L <= R) {
            mid = (L + R) >> 1;
            if(mid & 1) mid--;                              // make mid even to check for required condition
            if(mid+1 < n && nums[mid] == nums[mid+1])       // condition satisfied upto mid+1:
                L = mid+2;                                  // so search in [mid+2, R] to find point where condition starts to fail
            else                                            // condition not satisfied:
                R = mid-1, ans = nums[mid];                 // nums[mid] is potential answer. search [L, mid-1] to see if condition started to fail somewhere before
        }
        return ans;
    }
};