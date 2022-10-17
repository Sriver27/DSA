class Solution {
public:
    bool checkIfPangram(string sentence) {
        
     vector<int> mp(26);
        
        for(auto ch:sentence)
        {
            
            mp[ch-'a']++;
        }
        
        for(auto it:mp)
        {
            if(it == 0) return false; 
        }
        
        return true;
        
        
    }
};