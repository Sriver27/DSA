class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i= 0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j] != 0) // shift all non-zero elements to left and ignore all 0's
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};