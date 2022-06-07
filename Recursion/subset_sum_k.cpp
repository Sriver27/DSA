#include <iostream>
#include <vector>
using namespace std;

void helper(int i,vector<int> &arr,int n,int k,int sumTillNow, vector<int> &temp,vector<vector<int>> &ans)
{
    //base cases
    if(sumTillNow == k)
    {
        ans.push_back(temp);
        return;
    }
    if(sumTillNow > k) return;
    
    if(i == n) return;
    //pick
    sumTillNow+=arr[i];
    temp.push_back(arr[i]);
    helper(i+1,arr,n,k,sumTillNow,temp,ans);
    
    sumTillNow-=arr[i];
    temp.pop_back();
    
    //skip
    helper(i+1,arr,n,k,sumTillNow,temp,ans);
    
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0,arr,n,k,0,temp,ans);
   
    
    return ans;
}

int main(){
    vector<int> v={-9,4,-6,7};
    vector<vector<int>> ans;
    ans = findSubsetsThatSumToK(v,4,-2);

  
 
}