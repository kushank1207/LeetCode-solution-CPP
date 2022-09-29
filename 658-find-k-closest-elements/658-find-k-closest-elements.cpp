class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        
        for(int i : arr) {
            maxh.push(make_pair(abs(i-x), i));
            if(maxh.size() > k)
                maxh.pop();
        }
        
        vector<int> ans;
        while(maxh.size() > 0) {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};