class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int s = 0, e = nums.size()-1, mid = 0;
        while(mid<=e){
            switch(nums[mid]){
                case 0 :{
                    swap(nums[s++],nums[mid++]);
                    break;
                }
                case 1:{
                    mid++;
                    break;
                }
                case 2:{
                    swap(nums[e--], nums[mid]);
                    break;
                }
            }
        }
        
    }
};