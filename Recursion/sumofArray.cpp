#include<iostream>
using namespace std;

int arraySum(int *arr,int size)
{
    //base condition 
    if(size==0 )  {
        return 0;}
        if(size==1) {
            return arr[0];
        }

        //recursive relation
    return arr[0]+arraySum(arr+1,size-1);
   

}

int main(){
    int arr[5]={2,4,10,7,9};
    int size=5;

    int sum= arraySum(arr,size);

    cout<<"The sum of the numbers of the array is:"<<sum<<endl;
}