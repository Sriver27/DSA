#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){

    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    return -1;
}

int main(){

int even[8]={1,5,8,10,13,19,22,30};
int odd[5]={0,11,15,20,27};

int evenIndex=binarySearch(even,8,22);
cout<<"Key found at position:"<<evenIndex<<endl;
int oddIndex=binarySearch(odd,5,9);
cout<<"Key found at position:"<<oddIndex<<endl;


}