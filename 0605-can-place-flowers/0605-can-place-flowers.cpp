class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int size = flowerbed.size()-1;
        for(int i = 0; i<=size; i++)
        {
            if(flowerbed[i] == 1 or ((i-1)>=0 && flowerbed[i-1] != 0) or ((i+1)<=size && flowerbed[i+1]!=0)) continue;
            else{
                flowerbed[i] = 1;
                if(n > 0) n--;
            }
        }
        
        return n<=0;
        
    }
};