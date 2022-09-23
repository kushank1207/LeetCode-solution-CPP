class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN, max_arr = 0;
        
        for(int i=0; i<nums.size(); i++) {
            max_arr += nums[i];
            
            if(maximum < max_arr)
                maximum = max_arr;
            if(max_arr < 0) 
                max_arr = 0;
        }
        
        return maximum;
    }
};