class Solution {
public:
        
        bool uniqueOccurrences(vector<int>& arr) {
            
            unordered_map<int, int> m;
            unordered_set<int> s;
            
            for (auto n : arr) ++m[n];
            
            for (auto& p : m)
                if(!s.insert(p.second).second) return false; // returns false in case if element is already present
            
            return true;
    }
        
    
};