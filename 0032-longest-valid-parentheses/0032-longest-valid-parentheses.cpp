class Solution {
public:
    int longestValidParentheses(string s) {
        
 stack<int>stck;
        stck.push(-1);
        int res=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(') stck.push(i);
            
            else{
                stck.pop();
                if(stck.empty()) stck.push(i);
                else{
                    res = max(res,i-stck.top());
                }
            }
        }
        
        return res;
    }
};