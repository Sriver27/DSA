class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.size()==1)
            return 1;
        sort(nums.begin(),nums.end());
        int ans=1;
        int i=1;
        int mn=nums[0];
        while(i<nums.size())
        {
            if(abs(mn-nums[i])>k)
            {
                ans++;
                mn=nums[i];
            }
            i++;
        }
        
        
        return ans;
    }
};