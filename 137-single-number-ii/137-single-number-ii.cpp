class Solution {
public:
    int findUnique(vector<int>& nums, int n, int k)
{
    // Create a count array to store count of
    // numbers that have a particular bit set.
    // count[i] stores count of array elements
    // with i-th bit set.
    
    int count[32];
    memset(count, 0, sizeof(count));
 
    // AND(bitwise) each element of the array
    // with each set digit (one at a time)
    // to get the count of set bits at each
    // position
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < n; j++)
            if ((nums[j] & (1 << i)) != 0)
                count[i] += 1;
 
    // Now consider all bits whose count is
    // not multiple of k to form the required
    // number.
    unsigned res = 0;
    for (int i = 0; i < 32; i++)
        res += (count[i] % k) * (1 << i);
 
    // Before returning the res we need
    // to check the occurrence  of that
    // unique element and divide it
    res = res / (n % k);
    return res;
}
    int singleNumber(vector<int>& nums) {
        
        return findUnique(nums,nums.size(),3);
    }
};