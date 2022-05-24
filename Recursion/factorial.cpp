#include<iostream>
using namespace std;

int factorial(int n){
    // base condition
    if(n==0) return 1;
    else{
        // recursive relation
        return n*factorial(n-1);
    }
}

int main(){
    int n;
    cout<<"Enter a number :";
    cin>>n;

    int ans=factorial(n);
    cout<<ans<<endl;
    return 0;
}