#include<ctype.h>
class Solution {
public:
    int calPoints(vector<string>& operations) {
       vector<int> record;
        for (string ch : operations) {
            if (ch == "C")
                record.pop_back();
            else if (ch == "D")
                record.push_back(record.back() * 2);
            else if (ch == "+")
                record.push_back(record.back() + record[record.size() - 2]);
            else
                record.push_back(stoi(ch));
        }
        
        return accumulate(record.begin(), record.end(), 0);
    }
};