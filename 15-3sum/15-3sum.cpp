class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());    //Sorted Array
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){     //Traversing the array to fix the number.
            
            int temp = nums[i];
            int target = -temp;
            int s = i+1, e = n-1;
            
            while(s<e)
            {
                if(nums[s]+nums[e] == target)
                {
                    ans.push_back({nums[i],nums[s],nums[e]});
                    while(s<e && nums[s] == nums[s+1]) s++;
                    while(s<e && nums[e]==nums[e-1]) e--;
                    
                    s++,e--;
                }
                
                else if(nums[s]+nums[e] > target) e--;
                
                else s++;
            }
            
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;      //Return the answer vector.
    }
};