// BRUTE FORCE ->

// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
//         vector<int> ans;
//         int count = 0;
//         for(int i = 0;i < spells.size();i++){
//             for(int j =0 ;j < potions.size();j++){
//                 if(spells[i] * potions[j] >= success) count++;
//             }
//             ans.push_back(count);
//             count = 0 ;
//         }
        
//         return ans;
        
//     }
// };



// If ith potion is successful then all the potions after will be successful.
// So find the first potion which is successful using Binary Search.
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> res;
        int n(size(potions));
        sort(begin(potions), end(potions));
        
        for (auto& spell : spells) {
            int start(0), end(n);
            while (start < end) {
                int mid = start + (end-start)/2;
                ((long long)spell*potions[mid] >= success) ? end = mid : start = mid+1;
            }
            res.push_back(n-start);
        }
        return res;
    }
};