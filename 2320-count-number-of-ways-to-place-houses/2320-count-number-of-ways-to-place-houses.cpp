// This particular question resembles to fibo series
// <---------- One side of road has no effect on other side. Hence return no. of possibility on one side of road * possibility on one side of road ------------->

// for n = 1 --> 2*2 ways are possible with 2 ways on each side
//      n = 2 --> 3*3 ways are possible with 3 ways on each side
//      n = 3 --> 5*5 ways are possible with 5 ways on each side

class Solution {
public:
   int countHousePlacements(int n) {
        int a = 1, b = 1, c = 2, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
        return 1L * b * b % mod;
    }
};