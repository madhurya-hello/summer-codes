#include <iostream>
using namespace std;

int main()
{
    int arr[5]={2,5,1,7,8}; // unsorted array
    int n=5; // size of array
    
    for (int x=1; x<n; x++){
        bool opt=true;
        
        for(int i=0; i<n-1; i++){
           if (arr[i]>arr[i+1]){
                // swap
                int temp;
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
                opt=false;
            }
        }
        
        if(opt==true){
            break;
        }    
    }
    
    // printing the sorted array
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    
}