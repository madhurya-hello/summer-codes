#include <iostream>
using namespace std;

int main()
{
    int arr[5]={2,5,1,7,8}; // unsorted array
    int n=5; // size of array
    
    for(int i=0; i<n-1; i++){
        
        int minIndex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        
        if(arr[minIndex]<arr[i]){
            int temp=arr[minIndex];
            arr[minIndex]=arr[i];
            arr[i]=temp;
        }
    }
    
    
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}