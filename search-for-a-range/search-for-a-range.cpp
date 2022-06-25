class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        int res = -1;
        while(i<=j) {
            int mid = i+(j-i)/2;
            
            if(nums[mid] == target) {
                res = mid;
                j=mid-1;
            }

            else {
                if(nums[mid] > target)
                    j=mid-1;
                else if(nums[mid] < target)
                    i=mid+1;
            }
        }
        return res;
    }
    
    int lastOccurence(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        int res = -1;
        while(i<=j) {
            int mid = i+(j-i)/2;
            
            if(nums[mid] == target) {
                res = mid;
                i=mid+1;
            }

            else {
                if(nums[mid] > target)
                    j=mid-1;
                else if(nums[mid] < target)
                    i=mid+1;
            }
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0)
            return {-1,-1};
        ans.push_back(firstOccurence(nums, target));
        ans.push_back(lastOccurence(nums, target));
        
        return ans;
    }
};