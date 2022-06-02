#include<iostream>
#include<vector>

using namespace std;

void helper(int idx,int no,int n,vector<int> &v,vector<int> &ans,bool &found){

    if(idx>=2*n || idx+no+1>=2*n || v[idx]!=-1 || v[idx+no+1]!=-1)
        return;
    
    v[idx]=no;
    v[idx+no+1]=no;
    
    if(no==1){
        ans=v;
        v[idx]=-1;
        v[idx+no+1]=-1;
        found=true;
        return;
    }

    for(int i=0;i<2*n;i++){
        if(found)
            break;
        if(v[i]==-1)
            helper(i,no-1,n,v,ans,found);
    }
    
    v[idx]=-1;
    v[idx+no+1]=-1;
}

vector<int> findLangford(int n) 
{
    // Write your code here.
    vector<int> ans;
    if(n==0){
        return ans;
    }

    vector<int> v(2*n,-1);
    bool f=false;
    for(int i=0;i<2*n;i++){
        if(f) break;
        helper(i,n,n,v,ans,f);
    }
    
    if(ans.size())
    return ans;
    ans.push_back(-1);
    return ans;
} 

int main(){
    int n = 4;
    vector<int> ans(2*n,-1);

    ans= findLangford(n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    } 
}