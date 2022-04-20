//link : https://www.codingninjas.com/codestudio/problems/allocate-books_1090540

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studCount =1;
    int pageSum =0;
    for(int i=0; i<n;i++)
    {
        if(pageSum+ arr[i]<=mid)
        {
            pageSum += arr[i];
        }
        else{
             studCount++;
            if(studCount>m || arr[i]>mid){
                return false;
            }
            pageSum= arr[i];
        }
        
           
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int e= sum;
    int ans= -1;
    int mid = s+ (e-s)/2;
    while(s<=e)
    {
        
        if(isPossible(arr,n,m,mid))
        {
           ans= mid;
            e= mid-1;
        }
        else{
            s= mid+1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}


-----------------------------------------------------------------------------------------------------------------

// Application: https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

bool isPossible(int n,int m, vector<int> time,long long int mid)
{
    int dayCount=1;
    long long int timeSum=0;
    for(int i=0;i<m;i++)
    {
        if(timeSum+ time[i]<=mid)
        {
            timeSum+=time[i];
        }
        else
        {
            dayCount++;
        if(dayCount>n || time[i]>mid)
        {
            return false;
        }
        timeSum=time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int s=0;
    long long int sum=0;
    long long int ans=-1;
    for(int i=0;i<m;i++)
    {
        sum+=time[i];
    }
    long long int e= sum;
    long long int mid = s+(e-s)/2;
    while(s<=e)
    {
         if(isPossible(n,m,time,mid))
         {
             ans= mid;
             e= mid-1;
         }
        else
        {
            s= mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
   
}


----------------------------------------------------------------------------------------------------------

//Application : https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

bool isPossible(vector<int> &boards, int k,int mid)
{
    int sum=0;
    int painterCount=1;
    for(int i=0;i<boards.size();i++)
    {
        if(sum+boards[i]<=mid)
        {
            sum+=boards[i];
        }
        else
        {
            painterCount++;
            if(painterCount>k || boards[i]> mid)
            {
                return false;
            }
            sum=boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
   int s=0;
    int total=0;
    int ans=-1;
    for(int i=0;i<boards.size();i++)
    {
        total+=boards[i];
    }
    int e= total;
    int mid= s+ (e-s)/2;
    while(s<=e)
    {
        if(isPossible(boards,k,mid))
        {
            e= mid-1;
            ans=mid;
        }
        else
        {
            s= mid+1;
        }
        mid= s+ (e-s)/2;
    }
    return ans;
}


-----------------------------------------------------------------------------------------------

//Application: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1


bool isPossible(vector<int> &stalls, int k, int mid){
	int cowCount=1;
	int lastPos= stalls[0];
	
	for(int i=0;i<stalls.size();i++){
		if(stalls[i]-lastPos>=mid){
			cowCount++;
			if(cowCount==k){
				return true;
			}
			lastPos=stalls[i];
		}
	}
	return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
	sort(stalls.begin(),stalls.end());
   int s=0;
	int maxi=-1;
	for(int i=0;i<stalls.size();i++){
		maxi=max(maxi,stalls[i]);
	}
	int e=maxi;
	int mid=s+(e-s)/2;
	int ans=-1;
	while(s<=e){
		if(isPossible(stalls,k,mid)){
			ans=mid;
			s=mid+1;// to find the maximum distance
		}
		else{
			e=mid-1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}