#include <iostream>
using namespace std;

int main()
{
    int arr[5]={2,5,1,7,8}; // unsorted array
    int n=5; // size of array
    
    for(int i=1; i<n; i++){
        int temp=arr[i];
        for(int j=i-1; j>=0; j--){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            else{
                arr[j+1]=temp;
                break;
            }
        }
    }
    
    // printing the array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    
}