//TC : O(nlogn)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());   //after sorting the difference between consecutive elements becomes smallest
        int min=99999999;
        for(int i=0;i<arr.size()-1;i++)
        {
            if((arr[i+1]-arr[i])<min)
                min=(arr[i+1]-arr[i]);
        }
        vector<vector<int>>v;
        for(int i=0;i<arr.size()-1;i++)
        {
                if((arr[i+1]-arr[i])==min)     //checking for pair with difference equal to minimum
                    v.push_back({arr[i],arr[i+1]});
        }
        return v;
    }
};