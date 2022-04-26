// https://leetcode.com/contest/weekly-contest-290/problems/intersection-of-multiple-arrays/


class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        int n= nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
            sort(nums[i].begin(),nums[i].end());
            for(int j=0;j<nums[0].size();j++)// taking the first row
            {
                int cnt=0;
                int search=nums[0][j];
                for(int i=0;i<n;i++)
                    if(binary_search(nums[i].begin(),nums[i].end(),search))
                        cnt++;
                if(cnt==n)// ie. number is present throughout n rows
                    ans.push_back(search);
                
                
               
            }
             
        
        return ans;
        
    }
};