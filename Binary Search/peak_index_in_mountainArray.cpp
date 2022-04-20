//Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/


// Solution 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();

    }
};


// Solution 2

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e= arr.size()-1;
        int mid= s+(e-s)/2;
        
        while(s<e){
            
            if(arr[mid]<arr[mid+1]){
                
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid= s+(e-s)/2;
            
        }
        return s;

    }
};

// Solution 3

class Solution{
    public:
int peakIndexInMountainArray2(vector<int> A) {
        for (int i = 1; i + 1 < A.size(); ++i) if (A[i] > A[i + 1]) return i;
    }
    
};
