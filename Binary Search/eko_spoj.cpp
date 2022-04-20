#include <iostream>
#include<vector>
#include<math.h>

using namespace std;
int height(vector <long long int> v, long long int n, long long int m, long long int mid)
{
    long long int sum =0;
    for(int i=0;i<n;i++)
    {
        if(mid<v[i])
        {
            sum+=v[i]-mid;
        }
        if(sum>=m)
        {
            return true;
        }
    }
    return false;
}
int eko(vector <long long int> v, long long int n, long long int m)
{
    long long int s=0;
    int maxi=-1;
    for(int i=0; i<v.size(); i++){

        if(maxi<v[i]){
            maxi=v[i];
        }

    }
    long long int e= maxi;
    int mid= s+ (e-s)/2;
    int ans= 0;
    while(s<=e)
    {
        if(height(v,n,m,mid))
        {
            ans= mid;
            s=mid+1;
           
        }
        else
        {
             e=mid-1;
        }
         mid= s+ (e-s)/2;
    }
    return ans;
 }



 int main()
 {
    long long int n;
    long long int m;
    cin>>n>>m;
    
    vector <long long int> v;
    for(int i=0;i<n;i++)
    {
        long long int x;
        cin>>x;
        v.push_back(x);
 
    }
//  sort(v.begin(),v.end());
    cout<<eko(v,n,m);
 }