class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        int dp[nums.size()+1];
        
        dp[0] = nums[0]*mp[nums[0]];
        
        if(nums[1] != nums[0] + 1)
            dp[1] = dp[0]+mp[nums[1]]*nums[1];
        else
            dp[1] = max(dp[0], mp[nums[1]]*nums[1]);
        
        for(int i=2; i<nums.size(); i++) {
            if(nums[i] != nums[i-1] + 1)
                dp[i] = dp[i-1]+mp[nums[i]]*nums[i];
            else
                dp[i] = max(dp[i-1], dp[i-2]+mp[nums[i]]*nums[i]);
        }
        
        return dp[nums.size()-1];
    }
};