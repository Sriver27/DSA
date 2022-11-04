class Solution {
public:
    string reverseVowels(string s) {
        
        int start=0, end = s.size()-1;
        
        
while(start<=end)
{
            
  bool flag1=false,flag2=false;
                             if(s[start]=='a'||s[start]=='e'||s[start]=='i'||s[start]=='o'||s[start]=='u'||s[start]=='A'||s[start]=='E'||s[start]=='I'||s[start]=='O'||s[start]=='U')
                flag1 = true;
            
            if(s[end]=='a'||s[end]=='e'||s[end]=='i'||s[end]=='o'||s[end]=='u'||s[end]=='A'||s[end]=='E'||s[end]=='I'||s[end]=='O'||s[end]=='U')
                flag2 = true;
            
            if(flag1 && flag2)
            {
                swap(s[start++],s[end--]);
            }
            
            if(!flag1) start++;
            
            if(!flag2) end--;
        }
        return s;
    }
};