// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

bool arraySortedOrNot(int arr[], int n) {
        // code here
        if(n<=1){
            return 1;
        }
        
        if(arr[0]>arr[1]){
            return 0;
        }
        return arraySortedOrNot(arr+1, n-1);
    }