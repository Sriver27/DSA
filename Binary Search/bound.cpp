#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int key){

    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){

        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    return ans;
}

int lastOcc(int arr[],int n,int key){

    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){

        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }
    return ans;
}

int main(){

int even[6]={0, 5, 5, 6 ,6 ,6};
int odd[5]={0,11,15,20,27};

int firstIndex=firstOcc(even,6,6);
int lastIndex=lastOcc(even,6,6);
cout<<"First Occurence of 6 is at index: "<<firstIndex<<endl;
cout<<"Last Occurence of 6 is at index: "<<lastIndex<<endl;



}