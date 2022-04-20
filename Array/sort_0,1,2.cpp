// Link : https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTab=0

void sort012(int *arr, int n)  // TC : O(n)
{
   int low = 0;
   int mid = 0;
   int high = n-1;
    
    while(mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++; 
            mid++;    
        }
        
        else if(arr[mid]==1)
         mid++;
        
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


-----------------------------------------------------------------------------------------------------------------

void sort012(int *arr, int n)
{
   int lownot0 = 0, highnot2 = n - 1;
    for (int i = 0; i < n; i++)
    {
        while (arr[lownot0] == 0)
            lownot0++;
        while (arr[highnot2] == 2)
            highnot2--;
        if (arr[i] == 2 && i < highnot2)
            std::swap(arr[i], arr[highnot2]);
        if (arr[i] == 0 && i > lownot0)
            std::swap(arr[i], arr[lownot0]);
    }
}