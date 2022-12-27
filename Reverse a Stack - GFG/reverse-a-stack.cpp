//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int>& myStack, int x) 
    {
        if(myStack.empty())
        {
            myStack.push(x);
            return;
        }
        int temp = myStack.top();
        myStack.pop();
        insertAtBottom(myStack, x);
        myStack.push(temp);
    }
    void Reverse(stack<int> &St){
        
        if(St.empty()) return;
        
        int num = St.top();
        St.pop();
        
        Reverse(St); // recursive call - we assume that this call will give us remaining stack reversed
        
        insertAtBottom(St,num);
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends