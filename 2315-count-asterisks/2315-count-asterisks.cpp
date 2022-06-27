class Solution {
    
public :
    
int countAsterisks(string s) {
    int res = 0, pipes = 0;
    for (auto ch : s) {
        pipes += ch == '|';
        res += ch == '*' && pipes % 2 == 0; 
    }
    return res;
}
};