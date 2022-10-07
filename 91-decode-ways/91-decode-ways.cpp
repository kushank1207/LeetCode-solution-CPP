class Solution {
public:
    int dp[100];
    
    int solve(string s, int i) {
        if(s[i] == '0')
            return 0;
        if(i >= s.length())
            return 1;
        if(dp[i] != 0)
            return dp[i];
        
        int res = solve(s, i+1);
        if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0' >=0 && s[i+1]-'0' < 7))) {
            res += solve(s, i+2);
        }
        return dp[i] = res;
    }
    
    int numDecodings(string s) {
        memset(dp, 0, sizeof(dp));
        // if(s[0] == '0')
        //     return 0;
        return solve(s, 0);
    }
};