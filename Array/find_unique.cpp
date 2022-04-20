// link : https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=0

// Note: Applying XOR property of a^a=0

int findUnique(int *arr, int size)
{
    int ans=0;
	for(int i=0;i<size;i++){
		ans= ans^arr[i];
	}
	return ans;
}