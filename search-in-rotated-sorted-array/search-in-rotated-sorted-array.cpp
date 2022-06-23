class Solution {
public:
    int BS(vector<int>& nums, int start, int end, int target) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    
    int findRotation(vector<int>& nums) {
        int N = nums.size();
        int start = 0,end = N-1;
        while(start<=end){
            int mid = start + (end - start)/2;
            int prev = (mid - 1 + N)%N;
            int next = (mid + 1)%N;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return mid;
            else if(nums[mid]>=nums[0])
                start = mid+1;
            else 
                end = mid-1;
        }
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int ans1 = -1, ans2 = -1;
        int index = findRotation(nums);
        ans1 = BS(nums, 0, index-1, target);
        ans2 = BS(nums, index, nums.size()-1, target);
        
        if(ans1 == -1 && ans2 == -1)
            return -1;
        else {
            if(ans1 == -1)
                return ans2;
            else
                return ans1;
        }
    }
};