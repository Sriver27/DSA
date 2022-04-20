// link: https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=0

// Note : To find duplicate number in an array that contains each number between 1 and ‘N’ - 1 at least once , we take a XOR with an array that contains numbers between 1 and ‘N’ - 1.

int findDuplicate(vector<int> &arr) 
{
    int ans=0;
	for(int i=0;i<arr.size();i++){
		ans=ans^arr[i];
	}
	for(int i=0;i<arr.size();i++){
		ans=ans^i;
	}
	return ans;
}
