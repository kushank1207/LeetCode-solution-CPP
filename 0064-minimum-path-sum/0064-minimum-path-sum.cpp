class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m+1][n+1];
        for(int i=0; i<m+1; i++)
            for(int j=0; j<n+1; j++)
                if(i==m || j==n)
                    dp[i][j] = INT_MAX;
        dp[m-1][n] = 0;
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
        return dp[0][0];
    }
};