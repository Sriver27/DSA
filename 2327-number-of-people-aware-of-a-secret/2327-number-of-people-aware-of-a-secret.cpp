class Solution {
    long MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> day(1001, 0); // represents the number of people who know the secret on day i
        int d = 1;  
        day[d] = 1; // day 1 has 1 person who knows the secret

        // iterate through days
        while(d <= n) {
            // as 1 person can tell secret to only 1 person per day
            // so persons on day i  can tell  secreat after delay days untill they forget it
            // so we simply add the number of people who know the secret on day d to all new days
            for(int j = d + delay; j <= min(d + forget - 1, n); j++) {
                day[j] = (day[j] + day[d]) % MOD;
            }
            d++;
        }
        long res = 0;
        // At last day only  last '''forget''' days persons can remember the secret
		// so simply add them
        for(int i = max(n - forget + 1, 0); i <= n; i++) {
            res = (res + day[i]) % MOD;
        }
        return res;
    }
};
