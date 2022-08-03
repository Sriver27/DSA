class Solution {
public:
    
    void helper(int i, int k, int n, vector<int> &subSet,vector<vector<int>> &ans)
    {
        // BASE CONDITIONS
        
        if(k==0){
            ans.push_back(subSet);
            return;
        }
        if(i>n) return;
        if(k>n-i+1)  // required no. of elements for subset is greater than the remaining numbers
            return;
        
        
        // RECURSIVE RELATIONS
        
        // considering the ith element
        subSet.push_back(i);
        helper(i+1,k-1,n,subSet,ans);
        
        //skipping the ith element
        subSet.pop_back();
        helper(i+1,k,n,subSet,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> subSet;
        vector<vector<int>> ans;
        
        helper(1,k,n,subSet,ans);
        
        return ans;
    }
};