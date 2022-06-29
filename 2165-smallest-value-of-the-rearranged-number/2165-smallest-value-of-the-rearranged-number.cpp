class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        sort(s.begin(), s.end());
        if (num <= 0) {
            return -1 * stoll(string(s.rbegin(), s.rend()));
        }
        int i = s.find_first_not_of('0');
        swap(s[0], s[i]);
        return stoll(s);
    }
}; // stoll : convert string --> long long int