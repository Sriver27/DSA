class Solution {
public:
    bool isPowerOfTwo(int n) {
        
         bitset<64>b(n);//as in power of 2 only 1 bit is set
             if(b.count()==1) return true;// count no of set bit
             else    return false;
       
        
    }
};