class Solution
{
private:
    bool isPossible(int arr[], int n, int k, int mid){
        int painterCount=1;
        int sum=0;
        for (int i=0; i<n; i++){
            if (sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                painterCount++;
                if (painterCount>n){
                    return false;
                }
                else if (arr[i]>mid){
                    return false;
                }
                
                sum=0;
                sum+=arr[i];
            }  
        }
        
        return true;
     
    }
public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int sum=0;
        for (int i=0; i<n; i++){
            sum+=arr[i];
        }
        
        int start=0, end=sum;
        int mid=start + (end-start)/2;
        
        int ans=-1;
        
        while(start<=end){
            if (isPossible(arr,n,k,mid)){
                ans=mid; // may be the possible answer
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start + (end-start)/2;
        
        }
        
        return ans;
    }
};