 int myCompare(string x, string y){
        
        string XY = x.append(y);
        string YX = y.append(x);
        
        return XY.compare(YX)>0 ? 1 : 0 ;
    }

class Solution {
public:
   
    string largestNumber(vector<int>& nums) {
        
        vector<string> container;
        
        for(int i : nums) container.push_back(to_string(i));
        
        sort(container.begin(),container.end(),myCompare);
        
        string result;
        
        for(int i=0;i<container.size();i++)  result+=container[i];
        
        return result[0]=='0'? "0" : result; // checked for when all numbers in num vector are 0
    }
};