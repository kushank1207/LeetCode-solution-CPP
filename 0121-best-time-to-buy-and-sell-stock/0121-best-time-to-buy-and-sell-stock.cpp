class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minLeft = prices[0], maxDiff = 0;
        
        for(int i=1; i<prices.size(); i++) {
            maxDiff = max(maxDiff, prices[i]-minLeft);
            minLeft = min(minLeft, prices[i]);
        }
        
        return maxDiff;
    }
};