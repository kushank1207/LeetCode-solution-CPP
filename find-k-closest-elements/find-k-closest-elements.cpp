class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxh;
        
        for(int i=0; i<arr.size(); i++) {
            maxh.push(make_pair(abs(x-arr[i]), arr[i]));
            if(maxh.size() > k) 
                maxh.pop();
        }
        vector<int> ans;
        int size = maxh.size();
        for(int i=0; i<size; i++) {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};