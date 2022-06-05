class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.size()==1)
            return 1;
        sort(nums.begin(),nums.end()); // it helps in finding the diff.
        int ans=0;
        int i=0;
       
        while(i<nums.size())
        {
            int j= i;
            
            while(j < nums.size() && nums[j]-nums[i]<=k)  j++;//increasing subsequence size and checking if the diff. lies within k
            ans++;//subsequence++
            i=j; // if a particular subsequence is found then we directly skip to the element after the found subsequence
        }
        
        
        return ans;
    }
};