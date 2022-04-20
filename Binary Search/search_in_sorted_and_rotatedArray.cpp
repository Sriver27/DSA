// link : https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

// O(log n)
int getPivot(vector<int>& arr,int n)
{
    int s=0;
    int e=n-1;
   
    while(s<e)
    {
         int mid= s+(e-s)/2;
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }  
        else
        {
            e=mid;
        }
        mid= s+(e-s)/2;
        
    }
    return s;
}
int BinarySearch(vector<int>& arr,int s, int e, int k)
{
    int start=s;
    int end= e;
  
    while(start<=end)
    {
          int mid= start+ (end-start)/2;
        if(arr[mid]==k)
            return mid;
        if(k>arr[mid])
            start=mid+1;
        else
            end=mid-1;
    }
  
    return -1;
}
int findPosition(vector<int>& arr, int n, int k)
{
    int pivot= getPivot(arr,n);
    if(k>=arr[pivot] && k<=arr[n-1])
    {
        //performing binary search on second line
        return BinarySearch(arr,pivot,n-1,k);
    }
    else
    {
        //performing binary search on first line
         return BinarySearch(arr,0,pivot-1,k);
    }
        
}




-----------------------------------------------------------------------------------------------------------------

// O(log n)

int findPosition(vector<int>& arr, int n, int k)
{
    int l = 0;

   int h = arr.size()-1;

   while(l <= h)

   {

       int mid = l + (h-l)/2;

       if(arr[mid] == k)

           return mid;

       if(arr[0] <= arr[mid]) // left part

       {

           if(arr[0] <= k && arr[mid] > k)

               h = mid-1;

           else

               l = mid+1;

       }

       else

       {

         if(k <= arr[n-1] && arr[mid] < k)

             l = mid+1;

           else

               h = mid-1;

       }

   }

   return -1;
}



