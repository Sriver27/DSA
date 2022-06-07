// Algorithm : 
//---------------
// 1. Initialize rank = 1 
// 2. Traverse in the string, for every char find the characters less than it.
// 3. Add all possible permutations with smaller characters to the rank and return the final rank.
#include<iostream>
#include<string>

using namespace std;

int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}
 
// A utility function to count smaller characters on right
// of arr[low]
int findSmallerInRight(string str, int low, int high)
{
    int countRight = 0, i;
 
    for (i = low + 1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;
 
    return countRight;
}
 
// A function to find rank of a string in all permutations
// of characters
int findRank(string str)
{
    int len = str.length();
    int mul = fact(len);
    int rank = 1;
    int countRight;
 
    int i;
    for (i = 0; i < len; ++i) {
        mul /= len - i;
 
        // count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i, len - 1);
 
        rank += countRight * mul;
    }
 
    return rank;
}
 


int main(){
    cout<<findRank("string");

    return 0;
}