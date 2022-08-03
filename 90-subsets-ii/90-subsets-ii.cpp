class Solution {
public:
    void helper(int i,vector<int> &v,int n,vector<int> &subset,vector<vector<int >> &powerset)
{
 // base condition
    if(i==n){
        powerset.push_back(subset);
        return;
    }
    else{
        //pick
        subset.push_back(v[i]);
        helper( i+1,v, n,subset,powerset);
            subset.pop_back();
        
        //skip
        while(i+1<v.size() && v[i]==v[i+1]) i++;
          helper( i+1,v, n,subset,powerset);
    }
        
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
     vector<int> subset;
    vector<vector<int>> powerset;
   
    helper( 0,nums, nums.size(),subset,powerset);
    sort(powerset.begin(),powerset.end());
    return powerset;
    }
};