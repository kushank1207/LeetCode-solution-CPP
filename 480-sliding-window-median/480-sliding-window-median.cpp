class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> large;
        unordered_map<int,int> mp;
        vector<double> ans;
        int i=0;
        while(i < k) {
            small.push(nums[i++]);
        }
        for(int j=0; j<k/2; j++) {
            large.push(small.top());
            small.pop();
        }
        
        while(true) {
            ans.push_back(k & 1 ? small.top() : ((double) small.top()+large.top())*0.5);
            
            if(i>=nums.size())
                break;
            
            int out_num = nums[i-k], in_num = nums[i++], balance = 0;
            
            balance += (out_num <= small.top() ? -1 : 1);
            mp[out_num]++;
            
            if(!small.empty() && in_num <= small.top()) {
                balance++;
                small.push(in_num);
            } else {
                balance--;
                large.push(in_num);
            }
            
            if(balance < 0) {
                small.push(large.top());
                large.pop();
                balance++;
            }
            if(balance > 0) {
                large.push(small.top());
                small.pop();
                balance--;
            }
            
            while(mp[small.top()]) {
                mp[small.top()]--;
                small.pop();
            }
            while(!large.empty() && mp[large.top()]){
                mp[large.top()]--;
                large.pop();
            }
        }
        return ans;
    }
};