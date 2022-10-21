class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        for(int i = 0; i < nums.size();i++){
            if(mp.count(nums[i]) && abs(mp[nums[i]] - i) <= k)   return true;   
            mp[nums[i]] = i;
        }
        return false;
    }
};


// ------ using set and sliding window concept---------->

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k)
//     {
//        unordered_set<int> s;
       
//        // Base conditions : 
//         if (k <= 0) return false;
//        if (k >= nums.size()) k = nums.size() - 1;
       
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i > k) s.erase(nums[i - k - 1]);// erasing previous window of size k when i > k
//            if (s.find(nums[i]) != s.end()) return true;
//            s.insert(nums[i]);
//        }
       
//        return false;
//     }
// };