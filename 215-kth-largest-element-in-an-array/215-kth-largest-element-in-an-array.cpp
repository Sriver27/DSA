//Here we find that element which has exactly k + 1 elements (including itself) lesser to it.
class Solution {
public:

    int check(vector<int>& arr,int& x, int& k){
        int cnt = 0;
        for(int& i : arr){
            if(i < x)   cnt++;
        }
        
        return cnt <= k;
    }
    
    int findKthLargest(vector<int>& arr, int k) {
        
        //Find low and high that is the range where our answer can lie. 
        int lo = *min_element(arr.begin(),arr.end()),
            hi = *max_element(arr.begin(),arr.end()), ans = 0;
        
        k = arr.size() - k;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(arr,mid,k)){
                
                //If the selected element which would be mid has less than k elements lesser to it then increase the number that is low = mid + 1.
                lo = mid + 1;
                ans = mid;
            }
            else{
                // Decrement the number and try to find a better answer
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};