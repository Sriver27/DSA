// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//         int ans = 0;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             ans^=nums[i];
//         }
        
//         cout<<ans<<endl;
        
//         for(int i = 1; i<nums.size(); i++)
//         {
//             ans^=i;
//         }
        
//         cout<<ans;
        
//         return ans;
        
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+1,0);
        for(int i=0;i<nums.size();i++)
        {
            if(v[nums[i]]!=0)
            {
                return nums[i];
            }
            else
            {
                v[nums[i]]++;
            }    
        }
        return -1;
    }
};