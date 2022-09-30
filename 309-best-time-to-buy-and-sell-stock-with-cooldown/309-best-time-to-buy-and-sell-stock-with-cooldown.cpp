class Solution {
public:
    int dp[5001][2];
    
    int dfs(int index, vector<int>& prices, bool cond) {
        if(index > prices.size()-1) 
            return 0;
        
        if(dp[index][cond] != -1)
            return dp[index][cond];
        
        if(cond) {
            int buy = dfs(index+1, prices, !cond) - prices[index];
            int cooldown = dfs(index+1, prices, cond);
            return dp[index][cond] = max(buy, cooldown);
        } else {
            int sell = dfs(index+2, prices, !cond) + prices[index];
            int cooldown = dfs(index+1, prices, cond);
            return dp[index][cond] = max(sell, cooldown);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, prices, 1);
    }
};