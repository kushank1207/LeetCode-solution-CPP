class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.length()+1];
        memset(dp, false, sizeof(dp));
        dp[s.length()] = true;
        for(int i=s.length()-1; i>=0; i--) {
            for(auto j:wordDict) {
                if(i + j.length() <= s.length() && s.substr(i,j.length()) == j)
                    dp[i] = dp[i+j.length()];
                if(dp[i])
                    break;
            }
        }
        return dp[0];
    }
};