class Solution {
public:
        
        bool uniqueOccurrences(vector<int>& arr) {
            
            unordered_map<int, int> mp;
            unordered_set<int> s;
            
            for (auto n : arr) ++mp[n];
            
            for (auto& p : mp) s.insert(p.second);
                
            
            
            return (mp.size() == s.size())? true:false;
    }
        
    
};