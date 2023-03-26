class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(s.size() == 0) return 0;
        
        int open = 0, close = 0;
        int maxi = 0;
        
        /* 0 ... n */
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='(') open++;
            else
                close++;
            
            if(open == close)
            {
                int len = open + close;
                maxi = max(maxi, len);
            }
            
            else if(close > open){
                close = 0; open = 0;
            }
        }
        
        open = 0, close = 0;
         /* n ... 0 */
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='(') open++;
            else
                close++;
            
            if(open == close)
            {
                int len = open + close;
                maxi = max(maxi, len);
            }
            
            else if(open > close){
                close = 0; open = 0;
            }
        }
        
        return maxi;
    }
};