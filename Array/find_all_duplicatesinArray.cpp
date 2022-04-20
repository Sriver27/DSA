// link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Note : To find all duplicates in an array we first sort the array and check wether current index number is equal to the next index number, if equal we store it in another vector

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};