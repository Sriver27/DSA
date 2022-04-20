#include<iostream>
using namespace std;
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int left=1,right=x,ans=-1;
        while(left<=right)
        {
            int mid= left+(right-left)/2;
            if(mid<=x/mid)
            {
                left=mid+1;
                ans=mid;
            }
            else
                right=mid-1;
        }
        return ans;
    }

    double morePrecision(int n, int precision, int tempSol){
        double factor=1;
        double ans=tempSol;

        for(int i=0; i<precision; i++){
            factor=factor/10;

            for(double j=ans;j*j<n;j=j+factor){
                ans=j;
            }
        }
        return ans;
    }


    int main(){
        int n;
        cout<<"Enter a number: ";
        cin>> n;

        int tempSol=mySqrt(n);
        cout<<"Answer is: "<<morePrecision(n,3,tempSol)<<endl;
    }
