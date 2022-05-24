#include<iostream>
using namespace std;

bool isSorted(int *arr,int size)
{
    //base condition 
    if(size==0 || size==1) {
        return true;}
    if(arr[0]>arr[1]){
        return false;}
    else{
        //recursive relation
        return isSorted(arr+1,size-1);
    }
   

}

int main(){
    int arr[5]={2,4,10,7,9};
    int size=5;

    bool ans= isSorted(arr,size);

    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
}