class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i = 0; i + 1 < n; i++){
            int sum = nums[i] + nums[i + 1];
            if(s.count(sum)) return true;
            s.insert(sum);
        }
        return false;
    }
};