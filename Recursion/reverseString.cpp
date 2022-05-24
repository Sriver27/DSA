#include<iostream>
using namespace std;

void reverse(string &str,int i,int j){

// base case
if(i>j){
    return;
}

swap(str[i++],str[j--]);

//recursive relation


reverse(str,i,j);
}

int main()
{
    string str="harsh";

     reverse(str,0,str.length()-1);
     cout<<str<<endl;
}