class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();
        string str;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
            {
                str.pop_back();    
            }
            else{
                str.push_back(s[i]);
            }
        }
        
        return str;
        
    }
};