// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// link : https://leetcode.com/problems/find-pivot-index/

/* note : When nums[i] finds the actual pivot:
(total - pivot) == sum(numbers to left of pivot) + sum(numbers to right of pivot). In that case 'sum(numbers to left of pivot)' == 'sum(numbers to right of pivot)' or '2 * sum_of_right'
Thus '2 * sum_of_right' == total - pivot, is true when nums[i] is the actual pivot, thus 'return i'.*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int total = 0;
        for (int num : nums) total += num;
        int sum = 0;
        for (int i = 0; i < nums.size(); sum += nums[i++])
            if (sum * 2 == total - nums[i])
                return i;
        
        return -1;
    }
};