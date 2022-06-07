#include<iostream>

using namespace std;

void generateParantheses(string output, int n, int open, int close,int i){
    if(i == 2*n) {
        cout<< output<<endl;
        return;
    }
    
    if(open < n){
        generateParantheses(output+'{',n,open+1,close,i+1);
    }
    if(close<open){
        generateParantheses(output+'}',n,open,close+1,i+1);
    }
}

void printParantheses(int n) {
   int i=0,open=0,close=0;
    string output;
    
    generateParantheses(output,n,open,close,i);
}

int main(){
    printParantheses(3);
}