class Solution {
public:
	vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
		unordered_map<int,int>mp;
		for(int i=0;i<size(nums);i++) mp[nums[i]] = i;
		for(auto val:operations){
			int ind = mp[val[0]];
			mp.erase(val[0]);
			mp[val[1]] = ind;
		}
		vector<int>res(size(nums));
		for(auto [val,i]:mp) res[i] = val;
		return res;
	}
};