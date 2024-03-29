//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        
        int s = 0, e = n-1, ans = -1, mid;
        
        while(s<=e)
        {
            mid = s+(e-s)/2;
            
            if(arr[mid] == k)
            {
                ans = mid;
                return ans;
            }
            
            else if(arr[mid] > k) e = mid -1;
            
            else s = mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends