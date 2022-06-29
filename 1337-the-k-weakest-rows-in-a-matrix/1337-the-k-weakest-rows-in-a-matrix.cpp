class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int,int>> maxh;
        
        for(int i=0; i<mat.size(); i++) {
            mp[i] = 0;
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 1) 
                    mp[i]++;    
            }
        }
        
        for(auto i : mp) {
            maxh.push(make_pair(i.second, i.first));
            if(maxh.size() > k) 
                maxh.pop();
        }
            
        vector<int> ans;
        while(maxh.size() > 0) {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};