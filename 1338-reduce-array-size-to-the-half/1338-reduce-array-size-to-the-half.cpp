class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int> m;
        // by default map orders the elements according to the keys in ascending order
        // therefore we will reverse the ordering ; frequency -> first, key-> second ; then store in desc. order
        
        for(auto x : arr){
            
            m[x]++;
            
        }
        
        multimap<int, int, greater<int>> map;// greater<int> helps to store in desc. order and moreover in multimap the key is also not req. to be unique
        
        for(auto it : m)
        {
            map.insert({it.second, it.first});
        }
        
        int n = arr.size();
        int sum = n;
        int count = 0;
        
        for(auto it = map.begin(); it != map.end(); it++)
        {
            sum-= it->first;
            count++;
            
            if(sum <= n/2)
            {
                return count;
            }
        }
        
        return count;
        
    }
};