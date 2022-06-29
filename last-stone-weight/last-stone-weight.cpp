class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        
        for(int i=0; i<stones.size(); i++) {
            maxh.push(stones[i]);
        }
        
        while(maxh.size() >= 2) {
            int Y = maxh.top();
            maxh.pop();
            int X = maxh.top();
            maxh.pop();
            if(X < Y) {
                maxh.push(Y-X);
            }
        }
        if(maxh.size() == 0)
            return 0;
        else 
            return maxh.top();
    }
};