class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        int ans = 0; 
        while(i > 0){
            ans += min(nums[i],nums[i-1]);
            i-=2;
        }
        return ans;
    }
};