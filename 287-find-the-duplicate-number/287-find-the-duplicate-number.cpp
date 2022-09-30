class Solution {
public:
//     int findDuplicate(vector<int>& nums) {
        
//         int ans = nums[0];
        
//         unordered_map<int,int> mp;
//         for(int i=0;i<nums.size();i++) mp[nums[i]]++;
	
// 	    if(mp.size()==1)
// 	    return ans;
	  
//         for(int i=1; i<nums.size(); i++)
//         {
//             ans^=nums[i];
//         }
        
//         cout<<ans<<endl;
        
//         for(int i = 1; i<nums.size(); i++)
//         {
//             ans^=i;
//         }
        
       
        
//         return ans;
        
//     }
    int findDuplicate(vector<int>& nums){
     unordered_set<int> s;
     
     for(int i=0; i<nums.size(); i++){
         if(s.find(nums[i])!=s.end()){
             return nums[i];
         }
         s.insert(nums[i]);
     }
     return -1;
 } 
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> v(n+1,0);
//         for(int i=0;i<nums.size();i++)
//         {
//             if(v[nums[i]]!=0)
//             {
//                 return nums[i];
//             }
//             else
//             {
//                 v[nums[i]]++;
//             }    
//         }
//         return -1;
//     }
// };