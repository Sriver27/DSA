//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        
        // create a map to store the count of each character
        unordered_map<char,int> mp;
        for(int i = 0; i< S.length(); i++){
            mp[S[i]]++;
        }
        
        string str = S;
        
        //use two pointers to remove duplicates
        bool forward = true;
        int left = 0;
        int right = str.length()-1;
        while(left <= right) {
            if(forward){
                // if the character at left pointer has a count greater than 1, remove it !
                if(mp[str[left]] > 1)
                {
                    mp[str[left]]--;
                    str.erase(left,1);
                    right --;
                    forward = !forward; // switch direction of pointer movement
                }
                else{
                    left++;
                }
            }
            else{
                // if the character at right pointer has a count greater than 1, remove it !
                if(mp[str[right]] > 1)
                {
                    mp[str[right]]--;
                    str.erase(right,1);
                    //left++;
                    forward = !forward; // switch direction of pointer movement
                }
                else{
                    right--;
                }
            }
        }
        return forward ? str : string(str.rbegin(), str.rend());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends