class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int sum=nums[0];
        
        int maximum = nums[0], max_arr = nums[0], minimum = nums[0], min_arr = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            max_arr = max(max_arr + nums[i], nums[i]);
            maximum = max(max_arr, maximum);
            
            min_arr = min(min_arr+nums[i], nums[i]);
            minimum = min(min_arr, minimum);
            sum += nums[i];
        }
        
        if(sum == minimum)
            return maximum;
        
        return max(maximum, sum-minimum);
    }
};