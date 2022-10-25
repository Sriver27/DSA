class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string a,b;
        
        for(auto it1 : word1) a+=it1;
        
        for(auto it2 : word2) b+=it2;
        
        if(a.compare(b)==0) return 1;
        
        return 0;
    }
};