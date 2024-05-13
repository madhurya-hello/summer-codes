// https://leetcode.com/problems/binary-search/

class Solution {
private:
    int find(vector<int> arr, int x, int s, int e){
        if (s>e){
            return -1;
        }
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        return find (arr, x, s, e);
    }
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        return find(nums, target, start, end);
    }
};

