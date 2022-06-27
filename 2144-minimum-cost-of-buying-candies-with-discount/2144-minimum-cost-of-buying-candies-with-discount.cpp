/*For the max value, we have to pay for it.
For the second max value, we still have to pay for it.
For the third max value, we can get it free one as bonus.
And continuely do this for the rest.

The the core of problem, is need to sort the input.
All A[i] with i % 3 == n % 3, we can get it for free.*/
    
class Solution {
public:
    int minimumCost(vector<int>& cost) {
    int res = 0;
    sort(rbegin(cost), rend(cost));
    for (int i = 0; i < cost.size(); ++i)
        res += i % 3 == 2 ? 0 : cost[i]; // skipping third candy cost if (i % 3) == 2
    return res;
}
};