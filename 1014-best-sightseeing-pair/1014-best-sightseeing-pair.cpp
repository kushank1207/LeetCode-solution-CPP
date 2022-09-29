class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeft=values[0]+0, maxSum=0;
        
        for(int i=1; i<values.size(); i++) {
            maxSum = max(maxSum, maxLeft+values[i]-i);
            maxLeft=max(maxLeft, values[i]+i);
        }
        return maxSum;
    }
};