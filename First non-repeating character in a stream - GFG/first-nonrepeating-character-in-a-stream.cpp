//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    queue<int> q;
		    unordered_map<char,int> count;
		    string ans = "";
		    
		    for(auto ch: A)
		    {
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty())
		        {
		            if(count[q.front()]>1)
		            {
		                //repeating
		                q.pop();
		            }
		            else{ // non-repeating character milgya....
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()) ans.push_back('#');
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends