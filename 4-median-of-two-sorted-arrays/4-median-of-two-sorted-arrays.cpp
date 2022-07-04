class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> large;
        
        for(int i=0; i<nums1.size(); i++) {
            small.push(nums1[i]);
            large.push(small.top());
            small.pop();
            
            if(small.size() < large.size()) {
                small.push(large.top());
                large.pop();
            }
        }
        for(int i=0; i<nums2.size(); i++) {
            small.push(nums2[i]);
            large.push(small.top());
            small.pop();
            
            if(small.size() < large.size()) {
                small.push(large.top());
                large.pop();
            }
        }
        
        if((nums1.size() + nums2.size()) % 2 == 0) {
            return ((double) small.top()+large.top())*0.5;
        } else 
            return small.top();
    }
};