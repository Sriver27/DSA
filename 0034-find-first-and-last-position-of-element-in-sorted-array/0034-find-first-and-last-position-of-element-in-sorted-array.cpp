// class Solution {
// public:
//     int Occurences(vector<int>& nums, int n, int key, string find)
//     {
//         int s = 0, e = n-1, ans = -1;
//         int mid = s+(e-s)/2;
        
//         while(s<=e)
//         {
//             if(nums[mid] == key)
//             {
//                 ans = mid;
//                 (find == "first")? e = mid - 1 : s = mid + 1;
//             }
            
//             else if(nums[mid] > key)
//             {
//                 e = mid-1;
//             }
//             else if(nums[mid] < key)
//             {
//                 s = mid+1;
//             }
            
//             mid = s+(e-s)/2;
//         }
        
//         return ans;
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
        
//         int n = nums.size();
//         pair<int,int> p;
//         p.first = Occurences(nums,n,target,"first");
//         p.second = Occurences(nums,n,target,"last");
//         vector<int> ans;
//         ans.push_back(p.first);
//         ans.push_back(p.second);
        
//         return ans;
        
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //5,7,8,8,8,8,10 target=8
        vector<int> result;
        int FirstInd=firstocr(nums,target);
        int LastInd=lastocr(nums,target);
        result.push_back(FirstInd);
        result.push_back(LastInd);
        
        return result;
}        
     
int firstocr(vector<int>& nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + ((e - s) / 2);
    int ans = -1;
  //  int a[];
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }

       mid = s + ((e - s) / 2);
    }
    return ans;
}


int lastocr(vector<int>& nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + ((e - s) / 2);
    int ans = -1;
   // int a[];
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }

        mid = s + ((e - s) / 2);
    }
    return ans;
}   
};