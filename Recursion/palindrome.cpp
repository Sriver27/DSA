#include<iostream>
using namespace std;

bool isPalindrome(string str,int i,int j){

// base case
if(i>j){
    return true;
}

if(str[i]!=str[j])
return false;

//recursive relation


isPalindrome(str,i+1,j-1);
}

int main()
{
    string str="hvj";

    bool checkPalindrome=isPalindrome(str,0,str.length()-1);
     if(checkPalindrome)
     {
         cout<<"It is palindrome"<<endl;
     }
     else{
         cout<<"It is not palindrome"<<endl;
     }

     return 0;
}