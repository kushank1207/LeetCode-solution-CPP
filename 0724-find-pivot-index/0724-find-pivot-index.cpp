class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int leftSum=0, rightSum=0, totalSum=0;
        for(int i:nums) {
            totalSum += i;
        }
        for(int i=0; i<nums.size(); i++) {
            rightSum = totalSum-nums[i]-leftSum;
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
 
        }
        return -1;
    }
};