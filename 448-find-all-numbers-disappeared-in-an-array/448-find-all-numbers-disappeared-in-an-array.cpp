class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
		
        // 1st for loop: nums = [4,3,2,7,8,2,3,1]
        for(int i = 0; i < nums.size(); i++)  // each iteration:
        {                                     // i = 0              i = 1               i = 2                ... i = 7
            int temp = nums[i];               // temp = 4           temp = 3            temp = -2            ... temp = -1
            temp = (temp > 0) ? temp : -temp; // temp = 4           temp = 3            temp = 2             ... temp = 1
            if(nums[temp-1] > 0)              // nums[3] > 0        nums[2] > 0         nums[1] > 0          ... nums[0] > 0
                nums[temp-1] *= -1;           // [4,3,2,-7,8,2,3,1] [4,3,-2,-7,8,2,3,1] [4,-3,-2,-7,8,2,3,1] ... [-4,-3,-2,-7,8,2,-3,-1]
        } 
		
		// 2nd for loop: nums = [-4,-3,-2,-7,8,2,-3,-1]
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)         // the 4th & 5th indexes are positive
                ans.push_back(i+1); // ans = [5,6]
				
        return ans;
    }
};