class Solution {
public:
    void reverseStringHelper(int l, int r, vector<char>& s)
    {
        // base case
        if(l >= r) return;
        
        swap(s[l], s[r]);
        
        reverseStringHelper(l+1,r-1,s);
        
    }
    void reverseString(vector<char>& s) {
        
        reverseStringHelper(0, s.size()-1,s);
        
    }
};