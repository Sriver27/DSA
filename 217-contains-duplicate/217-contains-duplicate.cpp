class Solution {
public:
//     bool containsDuplicate(vector<int>& nums) {
        
//         unordered_map<int,int> mp;
        
//         for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        
//         for(auto it : mp){
//             if(it.second > 1) return true;
            
//             else return false;
//         }
//         return false;
//     }
    
    bool containsDuplicate(vector<int>& nums) {
        
    map<int, bool> myMap;
        
    for (auto& num: nums) {
        if (myMap.find(num) != myMap.end())
            return true;
        else
            myMap[num] = true;
    }
    return false;
}

};