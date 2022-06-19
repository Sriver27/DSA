class Solution {
public:
    int minimumNumbers(int sum, int k) {
        if (sum == 0) return 0;
        for (int i = 1; i <= sum; ++i)
            if ((i * k) % 10 == sum % 10 && i * k <= sum) return i; // comparing the last digit and side by side comparing that if i*k has not exceeded the required sum
        return -1;
    }
};