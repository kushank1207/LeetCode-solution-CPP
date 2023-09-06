class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, curr_max = 0;
        
        for(int i=0; i<nums.size(); i++) {
            curr_max += nums[i];
            if(curr_max > max) max = curr_max;
            if(curr_max < 0) curr_max = 0;
        }
        
        return max;
    }
};