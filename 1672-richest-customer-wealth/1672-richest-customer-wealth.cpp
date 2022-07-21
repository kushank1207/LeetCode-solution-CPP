class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = INT_MIN;
        for(int i=0; i<accounts.size(); i++) {
            int currentSum = 0;
            for(int j=0; j<accounts[0].size(); j++) {
                currentSum += accounts[i][j];
            }
            sum = max(currentSum, sum);
        }
        return sum;
    }
};