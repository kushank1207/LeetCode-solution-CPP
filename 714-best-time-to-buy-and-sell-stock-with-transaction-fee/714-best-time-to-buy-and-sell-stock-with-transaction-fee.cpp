class Solution {
public:
    int dp[50001][2];
    
    int dfs(int index, vector<int>& prices, int fee, bool cond) {
        if(index > prices.size()-1) 
            return 0;
        
        if(dp[index][cond] != -1)
            return dp[index][cond];
        
        if(cond) {
            int buy = dfs(index+1, prices, fee, !cond) - prices[index];
            int not_buy = dfs(index+1, prices, fee, cond);
            return dp[index][cond] = max(buy, not_buy);
        } else {
            int sell = dfs(index+1, prices, fee, !cond) + prices[index] - fee;
            int not_sell = dfs(index+1, prices, fee, cond);
            return dp[index][cond] = max(sell, not_sell);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, prices, fee, 1);
    }
};