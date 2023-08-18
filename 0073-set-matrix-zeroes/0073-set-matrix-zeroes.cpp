class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    v.push_back({i,j});
                }
            }
        }
        for (auto it : v) {
            // cout << it.first << " " << it.second << endl;
            int row = it.first; // 0
            int col = it.second; // 3
            
            // col
            for(int i=0; i<m; i++) {
                matrix[i][col] = 0; 
            }
            
            // row
            for(int i=0; i<n; i++) {
                matrix[row][i] = 0;
            }
        }
        
    }
};