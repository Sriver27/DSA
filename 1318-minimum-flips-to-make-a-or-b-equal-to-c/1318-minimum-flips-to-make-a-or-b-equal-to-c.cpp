// WRONG ANS :

// class Solution {
// public:
//      // Function to count the set bits
//     int countSetBits(int n)
//     {
//         int count = 0;
//         while(n > 0){
//             n &= (n-1);
//             count++;
//         }
//         return count;
//     }
//     int minFlips(int a, int b, int c) {
        
//         return countSetBits(c ^ a|b)+countSetBits(a & b & c);
//     }
// };


class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a != 0 || b != 0 || c){
            //check the last bit
            int aBit = a & 1;
            int bBit = b & 1;
            int cBit = c & 1;
            if(cBit == 1 && bBit == 0 && aBit == 0){
                count ++; //if both zero then to make a || b = 1  atleast one 1 is needed
            }else if (cBit == 0){
                if(aBit == 1 && bBit == 1) count += 2;//if both 1 then both should be zero to make a || b = 0
                if(aBit + bBit == 1) count++;//if one is zero flip the other one
            }//shift to check for next digit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};