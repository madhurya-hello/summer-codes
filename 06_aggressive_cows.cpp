#include <iostream>
using namespace std;

bool isPossible(int arr[], int stall, int cow, int mid){
    int cowCount=1;
    int fixedPos=arr[0];
    for(int i=0; i<stall; i++){
        if(arr[i]-fixedPos==mid){
            cowCount++;
            if(cowCount==cow){
                return true;
            }
            fixedPos=arr[i];
        }
    }
    return false;
}

int main()
{
    int arr[5]={1,2,3,4,6}; // array of stalls (sorted)
    int stall=5; // no of stalls
    int cow=2; // no of cows
    
    int s=0, e=arr[stall-1];
    int mid=s+(e-s)/2;
    
    int ans=-1;
    while(s<e){
        if(isPossible(arr, stall, cow, mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    
    cout<<ans;
}