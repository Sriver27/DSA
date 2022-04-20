class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int left=1,right=x,ans=-1;
        while(left<=right)
        {
            int mid= left+(right-left)/2;
            if(mid<=x/mid)
            {
                left=mid+1;
                ans=mid;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};

--------------------------------------------------------------------------------------------------------------


int sqrtN(long long int N)
{
    long long s=0, e=N, ans, mid;   //long long due to some of test cases overflows integer limit.
        while(s<=e){             
            mid=s+(e-s)/2;
            if(N==0)
                return 0;
            if(mid*mid==N) return mid;     //if the 'mid' value ever gives the result, we simply return it.
            else if(mid*mid<N){             
                s=mid+1;        //if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
                ans=mid;        //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value. 
            }
            else 
                e=mid-1;       //if 'mid' value encountered gives greater result, we simply discard all the values greater than mid. 
        }
        return ans;  
}