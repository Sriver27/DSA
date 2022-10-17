class Solution {
public:
    void reverseStringHelper(int l, int r, vector<char>& s)
    {
        // base case
        if(l >= r) return;
        
        reverseStringHelper(l+1,r-1,s);
        
        swap(s[l], s[r]);
              
    }
    void reverseString(vector<char>& s) {
        
        reverseStringHelper(0, s.size()-1,s);
        
    }
};