class Solution {
public:
    int smallestRangeII(vector<int>& A, int k) {
        int n=A.size();
        if(n==1) return 0;
        sort(A.begin(),A.end());
        
        //This will be the answer when we increase or decrease all the elements by k
        int ans=A[n-1]-A[0];
        
        //Now what we do is iterate over all i's and increase all elements before it(including it) by k and decrease all             
        //elements after it and find ans for such a condition this is the best greedy approach to find answer
        //When we go by the above condition than the maximum element will be either the current element increased by k or the last element decreased by k i.e. mx=max(curr+k,last-k);
        //similarly the minimum element will be either the next element decreased by k or the first element increased by k i.e mn=min(next-k,first+k)
        //using these two values we will constantly update our answer as the minimum of two the previous ans and this ans
        ans=min(ans,max(A[0]+k,A[n-1]-k)-min(A[0]+k,A[1]-k));
        for(int i=1;i<n-1;i++){
            //increase A[i] and all the elements before it
            int mx=max(A[i]+k,A[n-1]-k);
            int mn=min(A[0]+k,A[i+1]-k);
            
            ans=min(ans,mx-mn);
        }
        
        return ans;
    }
};