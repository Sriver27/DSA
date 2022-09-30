class Solution {
public:
//     void sortColors(vector<int>& nums) {
        
//         int s = 0, e = nums.size()-1, mid = 0;
//         while(mid<=e){
//             switch(nums[mid]){
//                 case 0 :{
//                     swap(nums[s++],nums[mid++]);
//                     break;
//                 }
//                 case 1:{
//                     mid++;
//                     break;
//                 }
//                 case 2:{
//                     swap(nums[e--], nums[mid]);
//                     break;
//                 }
//             }
//         }
        
//     }
    
    
    
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        
        while(mid <= high)
        {
            
            if(nums[mid] == 0)
            {
             swap(nums[low],nums[mid]);
                low++, mid++;
            }
            
            else if(nums[mid] == 1) mid++;
            
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            
        }
    }
};