// https://www.geeksforgeeks.org/problems/sum-of-array2326/1

class Solution{
public:
	// function to return sum of elements
	// in an array of size n
	int totsum(int *arr, int n){
	    if(n==0){
	        return 0;
	    }
	    if(n==1){
	        return arr[0];
	    }
	    int remaining = totsum(arr+1, n-1);
	    int sum=arr[0]+remaining;
	    return sum;
	};
	
	int sum(int arr[], int n) {
	    // code here
	    totsum(arr, n);
	}
};