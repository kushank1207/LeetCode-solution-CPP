class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int steps = cost.size();
        vector<int> vect(steps, 0);
        
        vect[0] = cost[0];
        vect[1] = cost[1];
        
        for(int i=2; i<steps; i++) {
            vect[i] = cost[i] + min(vect[i-1], vect[i-2]);
        }
        
        return min(vect[steps-1], vect[steps-2]);
    }
};