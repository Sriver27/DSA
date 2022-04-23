void insertionSort(int n, vector<int> &arr){
    int i = 1;
    while(i<n){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>temp ){	//shift right
                arr[j+1]=arr[j];
            }
            else{	//already sorted | break
                break;
            }
            j--;	//updation for j
        }
        arr[j+1] = temp;	//coz we always stop on this either to place correct value after shifting, in case of not shifting we will overwrite the value again.
    	i++;
    }
}