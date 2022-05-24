// link : https://leetcode.com/problems/rotate-array/
#include<iostream>
#include<vector>
using namespace std;


    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> temp(n);
        for(int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]= nums[i];
        }
        nums= temp;
    }
   int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(9);
    int k;
    cout<<"Enter the value of rotation:";
    cin>>k;
    rotate(nums,k);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

}


