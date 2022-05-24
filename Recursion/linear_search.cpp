#include<iostream>
using namespace std;

bool linearSearch(int *arr,int size,int k)
{
    if(size==0){
        return false;
    }
    if(arr[0]==k)
    {
        return true;
    }
    return linearSearch(arr+1,size-1,k);
}

int main(){
    int arr[5]={3,1,5,13,7};
    int size=5;
    int key=9;

    bool ans= linearSearch(arr,size,key);
    if(ans){
        cout<<"Key found"<<endl;
    }
    else
    {
        cout<<"Key not found"<<endl;
    }
}