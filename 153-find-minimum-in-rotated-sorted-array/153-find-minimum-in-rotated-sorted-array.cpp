class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int s = 0, e = nums.size()-1;
        int mid = s + (e-s)/2;
        
        while(s<e)
        {
            if(nums[s] < nums[e]) return nums[s];
            if(nums[mid] >= nums[s])
                s= mid + 1;
            else
                e = mid;
            
            mid = s + (e-s)/2;
        }
        
        return nums[s];
        
    }
};