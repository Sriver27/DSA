class Solution {
private:
    int helper(vector<int>& nums,int start, int end, bool findMin) {
        if(start == end)
            return nums[start];
        
        // we will get the middle element 
        int mid = start + (end-start)/2;
        
        //Find the minimum of the left part and right part of the array if we have to find min
        if(findMin){
            return min(helper(nums,start,mid,true) , helper(nums,mid+1,end,false));
        }
        else{
            return max(helper(nums,start,mid,true) , helper(nums,mid+1,end,false));
        }
        return 0;
    }
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        
        //passing true because we have to find the minimum of the complete array firstly
        return helper(nums,0,n-1,true);
    }
};