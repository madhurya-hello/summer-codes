#include <iostream>
using namespace std;
int main()
{
    int arr[11]={3,4,5,7,9,6,2,1};  // mountain array
    int n=11;   // array length
    
    // finding the greatest element
    
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    
    while(s<e){
        if(arr[mid]<arr[mid+1]){    // element lies at the increasing slope
            s=mid+1;
        }
        else if(arr[mid]>arr[mid+1]){   // element may lie at the top or at the decreasing slope
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    
    // printing the answer
    
    cout<<"greatest element is: "<<arr[s];  // arr[e] may also be used
    
}
