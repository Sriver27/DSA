/*For the max value, we have to pay for it.
For the second max value, we still have to pay for it.
For the third max value, we can get it free one as bonus.
And continuely do this for the rest.

The the core of problem, is need to sort the input.
All A[i] with i % 3 == n % 3, we can get it for free.*/
    
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(), cost.end()); int minCost = 0, n = cost.size();
        
        for(int i = 0; i< cost.size(); i++){
            if(i % 3 != n % 3) minCost+= cost[i];
        }
        
        return minCost;
        
    }
};