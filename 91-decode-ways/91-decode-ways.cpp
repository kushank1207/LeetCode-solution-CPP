class Solution {
public:
//     int dp[100];
    
//     int solve(string s, int i) {
//         if(s[i] == '0')
//             return 0;
//         if(i >= s.length())
//             return 1;
//         if(dp[i] != 0)
//             return dp[i];
        
//         int res = solve(s, i+1);
//         if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0' >=0 && s[i+1]-'0' < 7))) {
//             res += solve(s, i+2);
//         }
//         return dp[i] = res;
//     }
    
    int numDecodings(string s) {
        // memset(dp, 0, sizeof(dp));
        if(s.front() == '0')
            return 0;
        
        vector<int> dp(s.length()+1);
        dp[0] = 1;
        
        for(int i=1; i<=s.length(); i++) {
            if(s[i-1] != '0') 
                dp[i] = dp[i-1];
            if(i>=2) {
                int x = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (10 <= x && x <= 26) 
                    dp[i] += dp[i - 2];
            }
        }
        
        return dp[s.length()];
    }
};