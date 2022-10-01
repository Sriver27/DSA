class Solution {
public:
    int firstOcc(vector<int>& nums, int n, int key)
    {
        int s = 0, e = n-1, ans = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e)
        {
            if(nums[mid] == key)
            {
                ans = mid;
                e = mid - 1;
            }
            
            else if(nums[mid] > key)
            {
                e = mid-1;
            }
            else if(nums[mid] < key)
            {
                s = mid+1;
            }
            
            mid = s+(e-s)/2;
        }
        
        return ans;
    }
    int lastOcc(vector<int>& nums, int n, int key)
    {
        int s = 0, e = n-1, ans = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e)
        {
            if(nums[mid] == key)
            {
                ans = mid;
                s = mid + 1;
            }
            
            else if(nums[mid] > key)
            {
                e = mid-1;
            }
            else if(nums[mid] < key)
            {
                s = mid+1;
            }
            
            mid = s+(e-s)/2;
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        pair<int,int> p;
        p.first = firstOcc(nums,n,target);
        p.second = lastOcc(nums,n,target);
        vector<int> ans;
        ans.push_back(p.first);
        ans.push_back(p.second);
        
        return ans;
        
    }
};