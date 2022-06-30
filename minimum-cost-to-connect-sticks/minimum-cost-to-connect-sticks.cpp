class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minh;
        int totalCost = 0;
        
        for(int i=0; i<sticks.size(); i++)
            minh.push(sticks[i]);
        
        while(minh.size() >= 2) {
            int a = minh.top();
            minh.pop();
            int b = minh.top();
            minh.pop();
            totalCost += (a+b);
            minh.push(a+b);
        }
        
        return totalCost;
    }
};