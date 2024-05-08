#include <iostream>

using namespace std;
int main()
{
    int n=26;
    int s=0, e=n;  // since root will obviously lie in this region
    int mid = s+(e-s)/2;
    
    
    int ans=-1;
    
    while(s<=e){
        long long int temp=mid*mid; // "long long int" is used since "mid*mid" may result into something greater than INT_MAX 
        if (temp>n)
            e=mid-1;
        else if (temp<n){
            ans=mid;
            s=mid+1;
        }
        else if (temp==n){
            ans=mid;
            break;
        }
        mid=s+(e-s)/2;
            
    }
    
  
    cout<<ans;
    
}