#include <iostream>
using namespace std;
int main()
{
    int arr[10]={1,2,3,3,4,5,5,5,6,7};  // sorted array
    int n=10;   // array length
    int t=5;    // target element
    
    // finding the first occurence
    
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    
    int firstOccurence=-1;
    
    while(s<=e){
        
        if (t>arr[mid])
            s=mid+1;
        else if(t<arr[mid])
            e=mid-1;
        else if (t==arr[mid]){
            firstOccurence=mid;
            e=mid-1;
        }
        
        mid=s+(e-s)/2;
    }
    
    // finding the last occurence
    
    s=0, e=n-1;
    mid=s+(e-s)/2;
    
    int lastOccurence=-1;
    
    while(s<=e){
        
        if (t>arr[mid])
            s=mid+1;
        else if(t<arr[mid])
            e=mid-1;
        else if (t==arr[mid]){
            lastOccurence=mid;
            s=mid+1;
        }
        
        mid=s+(e-s)/2;
    }
    
    // printing the answer
    
    int totalOccurence = lastOccurence-firstOccurence+1;
    cout<<"First Occurence: "<<firstOccurence<<"\nLast Occurence: "<<lastOccurence<<"\nNumber of Occurence: "<<totalOccurence;
}