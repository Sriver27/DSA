class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> mpp(256,-1);
        int left = 0, right = 0, len =0;
        int n= s.size();
        
        while(right < n){
            if(mpp[s[right]] != -1) // if it does exist
                left = max(mpp[s[right]]+1, left); // if it lies in left of left pointer then we're not gonna update it !
            
            mpp[s[right]] = right; // update the character last seen index
            len = max(len, right-left+1); // max (previous substring length recorded,current substring length in the range l-r)
            
            right++;
        }
        
        return len;
        
    }
};