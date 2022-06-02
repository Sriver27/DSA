#include<iostream>
#include<vector>
using namespace std;

void helper(int n,int k, vector<int> &v)
{
    cout<<"upar wale push back k number hoon:"<<n<<endl;
    v.push_back(n);

    if(n<=0)
    return;

    helper(n-k,k,v);
  
    cout<<"niche wale push back k number hoon:"<<n<<endl;
    v.push_back(n);
}

vector<int> printSeries(int n,int k) {
    vector<int> v;

   helper(n,k,v);

   return v;
}

int main()
{
     vector<int> v;
    int n,k;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Enter a iterator:";
    cin>>k;
    v=printSeries(n,k);

    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }
}