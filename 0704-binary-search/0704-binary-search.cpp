class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(nums[0] == target)
                return 0;
            else 
                return -1;
        }
        
        int i=0, j=nums.size();
        
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid] == target) 
                return mid;
            else if(nums[mid] > target)
                j = mid-1;
            else 
                i = mid+1;
        }
        return -1;
    }
};