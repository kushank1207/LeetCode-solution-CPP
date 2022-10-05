class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        int count = 0;
        for(int i=1; i<nums.size()-1; i++) {
            int a = nums[i]-nums[i-1];
            int b = nums[i+1]-nums[i];
            if(a == b) {
                dp[i] = dp[i-1]+1;
                count += dp[i];
            }
        }
        return count;
    }
};