class Solution {
public:
     // Function to count the set bits
    int countSetBits(int n)
    {
        int count = 0;
        while(n > 0){
            n &= (n-1);
            count++;
        }
        return count;
    }
    
    int minBitFlips(int start, int goal) {
        
        return countSetBits(start ^ goal);
        
    }
};