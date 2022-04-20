// link: https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

-----------------------------------------------------------------------------------------------------------
// TC : O(nm)

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){

vector<int> ans;
    for(int i=0; i<n;i++){
        int element = arr1[i];

        for(int j=0; j<m; j++){
            if(arr2[j] == element){
                ans.push_back(element);
                arr2[j] = -1;
                break;
            }
        }
    }
    return ans;
}



-----------------------------------------------------------------------------------------------------------------

// Note : Using two pointer approach

// TC : O(max(n,m))

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i=0,j=0;
while(i<n && j<m)
{
    if(arr1[i]==arr2[j])
        {
            i++,j++;
            ans.push_back(arr1[i]);
        }
       else if(arr1[i]>arr2[j])
       {
           j++;
       } 
    else
    {
        i++;
    }
            
}
      return ans;
        
    

}