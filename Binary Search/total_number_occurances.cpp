// note: this is an application of first and last occurance
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


int firstIndex=firstOcc(even,6,6);
int lastIndex=lastOcc(even,6,6);

cout<<"Total number of occurences of 6 is : "<<(lastIndex-firstIndex)+1<<endl;

}