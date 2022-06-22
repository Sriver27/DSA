// Great! This is my code inspired by your solution. Given ascii

// '('：40    ')'：41
// '['：91    ']'：93
// '{'：123   '}'：125
// Just use the trick that c/40->1,2,3

class Solution{
    
    public:

bool isValid(string s) {
    char trick[] = { ')', ']', '}' };
    stack<char> matching;
    for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            matching.push((c / '(') - 1);
        } else if (matching.empty()) {
            return false;
        } else if (c != trick[matching.top()]) {
            return false;
        } else {
            matching.pop();
        }
    }
    return matching.empty();
}
};