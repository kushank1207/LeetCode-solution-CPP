class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_total = 0;
        
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1]) 
                max_total += prices[i] - prices[i-1];
        }
        
        return max_total;
    }
};