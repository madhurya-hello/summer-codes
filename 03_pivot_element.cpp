#include <iostream>
using namespace std;
int main()
{
    // original array: arr[7]={1,2,3,5,7,10,11}
    
    int arr[7]={7,10,11,1,2,3,5}; // rotated array 
    int n=7;    // length of array
    
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    
    while(s<e){
        if(arr[mid]>arr[0])
            s=mid+1;
        else if(arr[mid]<arr[0])
            e=mid;
        mid=s+(e-s)/2;
    }
    
    int pivot=mid;  // declaring the pivot element globally
    
    // printing the pivot element
    cout<<arr[pivot];
    
    // searching a target element 't' in the rotated array
    
    int t=11;    // target element
    int targetIndex=-1; // so that it will print -1 if not found

    if (t>=arr[0]){
        s=0, e=pivot-1;
        mid=s+(e-s)/2;
        
        while(s<e){
            if(t>arr[mid])
                s=mid+1;
            else if(t<=arr[mid])
                e=mid;
            mid=s+(e-s)/2;
        }
    }
    
    else{
        s=pivot, e=n-1;
        mid=s+(e-s)/2;
        
        while(s<e){
            if(t>arr[mid])
                s=mid+1;
            else if(t<=arr[mid])
                e=mid;
            mid=s+(e-s)/2;
        }   
    }
    
    targetIndex = mid;

    // printing the index of the target element
    cout<<"\nelement found at: "<<targetIndex;
    
}