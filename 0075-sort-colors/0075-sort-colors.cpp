class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, first = 0, second = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) zero++;
            else if(nums[i]==1) first++;
            else second++;
        }
        int i=0;
        while(zero>0) {
            nums[i++] = 0;
            zero--;
        }
        while(first>0) {
            nums[i++] = 1;
            first--;
        }
        
        while(second>0) {
            nums[i++] = 2;
            second--;
        }
    }
};