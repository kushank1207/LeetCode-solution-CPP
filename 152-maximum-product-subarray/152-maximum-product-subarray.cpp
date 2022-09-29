class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dpMin[nums.size()], dpMax[nums.size()];
        
        dpMin[0] = nums[0];
        dpMax[0] = nums[0];
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++) {
            dpMin[i] = min(nums[i], nums[i]*(nums[i]>=0 ? dpMin[i-1] : dpMax[i-1]));
            dpMax[i] = max(nums[i], nums[i]*(nums[i]>=0 ? dpMax[i-1] : dpMin[i-1]));
            ans = max(ans, dpMax[i]);
        }
        
        return ans;
    }
};