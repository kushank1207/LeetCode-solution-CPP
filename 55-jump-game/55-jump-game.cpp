class Solution {
public:
    int dp[10001];
    int solve(int n, vector<int>& nums) {
        if(nums.size()-1 <= n) {
            return 1;
        }
        if(dp[n] != -1)
            return dp[n];
        
        int jump = nums[n];
        for(int i=1; i<=nums[n]; i++) {
            int res = solve(n+i, nums);
            if(res == 1) {
                return dp[n] = 1;
            }
        }
        return dp[n] = 0;
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    } 
};