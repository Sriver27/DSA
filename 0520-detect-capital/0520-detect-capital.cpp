class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cnt = 0;
        
        for(auto ch: word)
        {
            if(isupper(ch)) cnt++;
        }
        
        return !cnt || cnt == word.size() || cnt == 1 && isupper(word[0]);
        
    }
};