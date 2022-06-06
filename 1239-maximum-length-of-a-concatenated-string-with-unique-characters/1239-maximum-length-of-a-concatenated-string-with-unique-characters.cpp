class Solution {
public:
    bool compare(vector<int> &selected,string &currString)
{
    vector<int> selfCheck(26,0);
    for(int i=0;i<currString.size();i++){//checking for duplicate characters in currString
        if(selfCheck[currString[i]-'a'] == 1) return false;
        selfCheck[currString[i]-'a'] = 1 ;
    }
    for(int i=0;i<currString.size();i++){ // checking if the characters in currString has appeared earlier
         if(selected[currString[i]-'a'] == 1) return false;
    }
    return true;
}

int helper(int i, vector<string> &arr,vector<int> &selected,int len){
    
    //base case
    if(i==arr.size()){
        return len;
    }
    
    
    string currString = arr[i];
    if(compare(selected,currString) == false){ // if the characters in current string has been picked earlier or the current string itself has duplicate characters - skip it
        return helper(i+1,arr,selected,len);
    }
    else{
        //pick
        for(int j=0;j<currString.size();j++){
            selected[currString[j]-'a'] = 1;
        }
        len+=currString.size();
        int op1 = helper(i+1,arr,selected,len);
        
        //skip
             for(int j=0;j<currString.size();j++){
            selected[currString[j]-'a'] = 0;
        }
         len-=currString.size();
        int op2 = helper(i+1,arr,selected,len);
        
           return max(op1,op2);
    }
 
}

    int maxLength(vector<string>& arr) {
        
         vector<int> selected(26,0);
    return helper(0,arr,selected,0);
        
    }
};