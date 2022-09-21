class Solution {
public:
//     int HR(vector<int>& nums, int i, int j) {
//         int dp[j-i+2];
//         memset(dp,-1,sizeof(dp));
//         dp[0] = nums[i];
//         dp[1] = max(nums[i], nums[i+1]);
        
//         for(int k=i+2; k<=j; k++) {
//             dp[k] = max(nums[k]+dp[k-2], dp[k-1]);
//         }
        
//         if(dp[j] != -1)
//             return dp[j];
//         else 
//             return dp[j-1];
//     }
    int rob(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         if(nums.size() == 1)
//             return nums[0];
//         if(nums.size() == 2)
//             return max(nums[0],nums[1]);

//         int a1 = HR(nums, 0, nums.size()-2);
//         int a2 = HR(nums, 1, nums.size()-1);
//         return max(a1, a2);
        
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        
        int dp1[nums.size()];
        int dp2[nums.size()];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        
        // vector<int> dp1(nums.size(),0);
        // vector<int> dp2(nums.size(),0);
        
        dp1[0] = nums[0];
        dp1[1] = max(nums[1], dp1[0]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[2], dp2[0]);
        
        for(int k=2; k<nums.size()-1; k++) {
            dp1[k] = max(nums[k]+dp1[k-2], dp1[k-1]);
        }
        for(int k=2; k<nums.size()-1; k++) {
            dp2[k] = max(nums[k+1]+dp2[k-2], dp2[k-1]);
        }
        
        return max(dp1[nums.size()-2], dp2[nums.size()-2]);
    }
};