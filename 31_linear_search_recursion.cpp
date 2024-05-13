class Solution {
private:
    int find(vector<int> arr, int x, int i){
        if (i>=arr.size()){
            return -1;
        }
        if(arr[i]==x){
            return i;
        }

        return find(arr, x, i+1);
    }
public:
    int search(vector<int>& nums, int target) {
        int index=0;
        return find(nums, target, index);

    }
};
