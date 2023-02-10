//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        if(s == "ballon") return 1;
        if(s == "") return 0;
        
        map<char,int> mp;
        int cnt = 0;
        
        // mapping characters of string to their frequency
        for(auto it: s){
            mp[it]++;
        }
        
        //for(auto it:mp) cout<<it.first<<"->"<<it.second<<endl;
        
        while(mp['b']>0 && mp['a']>0 && mp['l']>1 && mp['o']>1 && mp['n']>0)
        {
            mp['b']-- ; mp['a']-- ; mp['l']-=2 ; mp['o']-=2;  mp['n']--;
            cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends