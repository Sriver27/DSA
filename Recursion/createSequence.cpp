#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

void helper(long long tempNumber , long long n , vector<long long> &ans)
{
    if(tempNumber > n) return;
    if(tempNumber != 0) ans.push_back(tempNumber);
    
    helper(tempNumber*10+2,n,ans);
    helper(tempNumber*10+5,n,ans);
}

vector<long long> createSequence(long long n){
 
    vector<long long> ans;
    helper(0,n,ans);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}

int main(){
    int n = 100;
    vector<long long> ans;

    ans= createSequence(n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    } 
}