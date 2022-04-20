// link : https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTab=0

// Note : Applying two pointer approach


vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	  vector<vector<int>> ans;

   sort(arr.begin() , arr.end());

   int left , right ;

   for(int i = 0 ; i<n ; i++)

   {

       left = i+1 ;

       right = n-1;

       while(left<right)

       {

           if(arr[left]+arr[right]+arr[i] == K)

           {

                ans.push_back({arr[i], arr[left], arr[right]});

               int x = arr[left] ;

               int y = arr[right] ;

               //skipping same elements

               while(left<right && arr[left]==x){

                   left++ ;

               }

                  while(left<right && arr[right]==y){

                   right-- ;

               }

           }

           else if(arr[left]+arr[right]+arr[i] < K){

               left++;

           }

           else{

               right--;

           }

       }

       //skipping same ith element

        while(i+1<n && arr[i]==arr[i+1]){

           i++ ;

       }

   }

   return ans;
}