class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int N = nums.size();
        if(nums[0] < nums[N-1] || nums.size() == 1)
            return nums[0];
        
        while(i<=j) {
            int mid = i + (j-i)/2;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid+1]) 
                return nums[mid+1];
            else if(nums[mid] > nums[N-1])
                i = mid+1;
            else 
                j = mid-1;
        }
        return -1;
    }
};