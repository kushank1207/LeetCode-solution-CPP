class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0, j=heights.size()-1;
        
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i=0; i<heights.size()-1; i++) {
            int climb = heights[i+1] - heights[i];
            
            if(climb <= 0)
                continue;
            
            minh.push(climb);
            
            if(minh.size() <= ladders)
                continue;
            
            bricks -= minh.top();
            
            minh.pop();
            
            if(bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};