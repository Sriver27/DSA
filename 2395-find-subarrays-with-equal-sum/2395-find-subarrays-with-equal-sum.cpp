class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        
        map<int,int> mp; // create a map for storing all pair sum ans their occurance 
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            mp[nums[i]+nums[i+1]]++; // each time incease the occurance of pair sum
        }
        
        for(auto it : mp) // iterate over the map
        {
            if(it.second>1) return true;// any point we get any pair sum occurance more than 1 just return true
        }
        return false;
    }  
};