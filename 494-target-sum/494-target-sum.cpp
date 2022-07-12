class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int N = nums.size();
        
        for(int i=0; i<N; i++)
            sum += nums[i];
        if((sum-target)%2 != 0 || (sum-target)< 0 || abs(target) > sum) 
            return 0;
        else {
            int subset = (target+sum)/2;
            int dp[N+1][subset+1];
        
            for(int i=0; i<N+1; i++) {
                for(int j=0; j<subset+1; j++) {
                    if(i==0)
                        dp[i][j] = 0;
                    if(j==0)
                        dp[i][j] = 1;
                }
            }
        
            for(int i=1; i<N+1; i++) {
                for(int j=0; j<subset+1; j++) {
                    if(nums[i-1] <= j) {
                        dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[N][subset];
        }
        
    }
};