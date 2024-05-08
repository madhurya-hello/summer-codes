#include <iostream>
using namespace std;

bool isPossible(int arr[], int book, int student, int mid){
    int bookSum=0;
    int studentCount=1;
    for (int i=0; i<book; i++){
        if (bookSum+arr[i]<=mid){
            bookSum+=arr[i];
        }
        else{
            studentCount++;
            if (studentCount>student){
                return false;
            }
            else if (arr[i]>mid){
                return false;
            }
            
            bookSum=0;
            bookSum+=arr[i];
        }  
    }
    return true;
}

int main()
{
    int arr[5]={10,20,30,40,50}; // array of books
    int book=5; // no of books
    int student=2; // no of students
    
    int sum=0;
    for (int i=0; i<book; i++){
        sum+=arr[i];
    }

    int s=0, e=sum;
    int mid=s+(e-s)/2;
    
    
    int ans=-1;
    while(s<=e){
        if(isPossible(arr, book, student, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
            
        mid=s+(e-s)/2;
    }
    
    cout<<ans;
    
}