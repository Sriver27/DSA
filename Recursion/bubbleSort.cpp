#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n)
{   
    if(n==0 || n==1)
		return;
	for(int i=0;i<n-1;i++){
	           if(arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
         
            } 
	}
	bubbleSort(arr,n-1);
}


int main(){

    int arr[5]={7,3,9,1,2};
    int size=5;

    bubbleSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}