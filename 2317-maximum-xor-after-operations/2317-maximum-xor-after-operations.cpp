/*let take some example
suppose arr = {1,2,3,9}
now we will find have bit of all these
1 -> 0001
2 -> 0010
3 -> 0011
9 -> 1001
now to get maximum answer we should have as many as 1 bits possible in 
answer so for that we need to use OR operation, 
so that we get maximum of 1 bits in every place of answer 

1011 as answer which is equal to 11.*/

class Solution {
public:
	int maximumXOR(vector<int>& nums) {
		int res = 0;
		for(auto x:nums) res|=x;
		return res;
	}
};