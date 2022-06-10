// Brute Force

// class Solution {
// public:
//     bool canPartition(vector<int>& nums, int i =0, int sum1 = 0, int sum2 = 0) {
//          if(i >= size(nums)) return sum1 == sum2;                    // check if both subset have equal sum
//         return canPartition(nums, i+1, sum1 + nums[i], sum2)        // try including into subset-1
// 		    || canPartition(nums, i+1, sum1, sum2 + nums[i]);       // try including into subset-2
//     }
    
// };



// Optimisation : We can slightly optimize the above approach by observing that equal partion are only possible when the total sum of array can be equally split, i.e, it is even. This effectively allows us to directly return false if the sum is odd. When the sum is even, we only need to check if we can construct one subset with its sum equal to total_sum / 2 (the other will automatically have the same sum, so we dont need to care about it). Thus the above can be optimized to -

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int totalSum = accumulate(begin(nums), end(nums), 0);
//         if(totalSum & 1) return false;
//         return subsetSum(nums, totalSum / 2);
//     }
//     bool subsetSum(vector<int>& nums, int sum, int i = 0) {
//         if(sum == 0) return true;                         // subset formed with required half-sum
//         if(i >= size(nums) || sum < 0) return false; 
//         return subsetSum(nums, sum - nums[i], i + 1)      // include current element
//             || subsetSum(nums, sum, i + 1);               // exclude current element
//     }
// };


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto n : nums) bits |= bits << n;
        return !(sum & 1) && bits[sum >> 1];
    }
};