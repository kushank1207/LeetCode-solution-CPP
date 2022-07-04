// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
  void solve(int k, int index, vector<int> &nums, int &ans){
    //Base condition
    if(nums.size()==1){
        ans=nums[0];
        return;
    }
    //Hypothesis
    index=(index+k)%nums.size();
    nums.erase(nums.begin()+index);
    solve(k,index,nums,ans);
    //No induction step
    return;
}
    int safePos(int n, int k) {
        // code here
        int ans=0;
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        solve(k-1,0,nums,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends