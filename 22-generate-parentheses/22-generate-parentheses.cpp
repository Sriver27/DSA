class Solution {
public:
    void helper(int i, int n, int open, int close, vector<string> &ans,string output)
    {
        if(i == 2*n){
            ans.push_back(output);
            return;
        }
        if(open < n){
            
            helper(i+1,n,open+1,close,ans,output+'(');   
        }
        
        if(close<open){
            helper(i+1,n,open,close+1,ans,output+')');   
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        int open=0, i=0, close=0;
        string output;
        
        helper(i,n,open,close,ans,output); 
        return ans;
    }
};