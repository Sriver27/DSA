// Just simply returning the max no. as the the max no. of 1's required to sum upto the decimal number are present in max no.

class Solution {
public:
    int minPartitions(string n) {
        
	int ans = 0;
	for(auto& ch : n) ans = max(ans, ch - '0');
	return ans;
	// or simply -
	// return *max_element(begin(n), end(n)) - '0';
        
    }
};