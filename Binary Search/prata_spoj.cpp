// link : https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0

bool isPossible(vector<int> &rank, int m,int mid){
	int dishCount=0;
		int time=0;
	for(int i=0;i<rank.size();i++){
		time=rank[i];
		int j=2;
		while(time<=mid){
			dishCount++;
			time+=(rank[i]*j);
			j++;
		}
		if(dishCount>=m){
			return true;
		}
	}
	return false;
}

int minCookTime(vector<int> &rank, int m)
{
    int s=0;
	int e=1e8;
	int mid=s+(e-s)/2;
	int ans=-1;
	
	while(s<=e){
		if(isPossible(rank,m,mid)){
			
			/*true, then the case might be true for
			all cases greater than 'mid' time*/
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
		
		mid=s+(e-s)/2;
	}
	return ans;
}