class Solution {
public:
    int dp[2001][2001];

    bool is_palindrome(string &s, int i, int j) {
        while(i<=j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int MCM(string s, int i, int j) {
        if(i >= j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(is_palindrome(s,i,j))
            return 0;
        
        int ans = INT_MAX;
        for(int k = i ; k<j ; k++)
        {
             if(!is_palindrome(s,i,k)) 
                continue;
            
            int right = 1 + MCM(s,k+1,j); 
            ans = min(right,ans);
        }
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));

        return MCM(s,0,s.length()-1);
    }
};