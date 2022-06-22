class Solution {
public:
    int kth_Largest(map<int,int> m, int k){
        int freq = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		freq += (it->second); // adding the frequencies of
							// each element
		if (freq >= k) // if at any point frequency becomes
					// greater than or equal to k then
					// return that element
		{
			return it->first;
		}
	}
	return -1; // returning -1 if k>size of the array which
			// is an impossible scenario
    }
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> m;
        
        for(int i =0;i<nums.size();i++){
            m[nums[i]]+=1;
        }
        
        int ans = kth_Largest(m, nums.size()-k+1);
        
        return ans;
    }
};