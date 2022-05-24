#include<iostream>
using namespace std;

bool binarySearch(int *arr,int s,int e,int k)
{
    // base case 
        //element not found
        if(s>e)
        {
            return false;
        }
        int mid=s+(e-s)/2;
        // element found
        if(arr[mid]==k){
            return true;
        }

        //recursive relations
        if(arr[mid]<k){
           return binarySearch(arr,mid+1,e,k);
        }
        else{
           return binarySearch(arr,s,mid-1,k);
        }

}

int main(){
    int arr[6]={2,5,7,11,18,27};
    int size=6;
    int key=9;

    bool ans= binarySearch(arr,0,size-1,key);
  
        cout<<"Present or not present"<<" "<<ans<<endl;
    

}