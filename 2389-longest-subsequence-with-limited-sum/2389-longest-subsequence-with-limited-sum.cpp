//BRUTE FORCE -->


// class Solution {
// public:
//     void helper(vector<int>& nums,int index,vector<int> subarray,vector<vector<int>>& ans){

 

//     if(index == nums.size()){
//         if(subarray.size()!=0)
//             ans.push_back(subarray);
//         return;
//     }
//     else{
//         subarray.push_back(nums[index]);
//         helper(nums,index+1,subarray,ans);
//         subarray.pop_back();
//         helper(nums,index+1,subarray,ans);
//     }
// }
//     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
//         vector<vector<int>> ans;
//     int sum = 0;
//     helper(nums,0,vector<int>(),ans);
//     vector<int> result;
//     for(auto& q: queries){
//         int max = 0;
//         for(auto& v: ans){
//             // sum of every element in v 
//              sum = 0;
//             for(auto& e: v){
//                 sum += e;
//             }
            
//             if(v.size()>max && sum<=q){
//                 max = v.size();
//             }
//         }
//         result.push_back(max);
        
//     }
//     return result;
        
//     }
// };




//OPTIMISED -->


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = nums.size();
        int m = queries.size();
        
        sort(nums.begin(),nums.end());
        int sum = 0;
        vector<int> pre_sum;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            pre_sum.push_back(sum);           // storing prefix sum
        }
        
        vector<int> ans(m,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pre_sum[j] <= queries[i]) ans[i] = j+1;          // wherever we got the max subsequence sum for i just update that
                else break;
            }
        }
        return ans;
    }
};