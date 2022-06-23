class Solution {
public:
    int BS(vector<int>& nums, int i, int j, int target) {
        if(j>=i){
            int mid=i+(j-i)/2;
            if(nums[mid] == target) 
                return mid;
            if(nums[mid] > target)
                return BS(nums, i, mid-1, target);
            
            return BS(nums, mid+1, j, target);
        }        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return BS(nums, 0,nums.size()-1, target);
    }
};