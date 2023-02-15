class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       
    /* BRUTE FORCE ----------------------- */
        
      /*long long val = 0, sum = 0;
        for(auto it: num) val = val * 10 + it;
        
        sum = val+k;
        
        vector<int> ans;
        int r;
        
        while(sum){
            r = sum % 10;
            ans.push_back(r);
            sum /= 10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans; */
        
    /* OPTIMISED ---------------------- */
        
        for(int i=num.size()-1;i>=0;i--){
            num[i] += k;
            k = num[i]/10;
            num[i] %= 10;
        }
        while(k > 0){
            num.insert(num.begin(), k%10);
            k /= 10;
        }
        return num;
        
    }
};