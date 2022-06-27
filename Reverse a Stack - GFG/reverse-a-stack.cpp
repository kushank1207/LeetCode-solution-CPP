// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert(stack<int>& St, vector<int>& v) {
        if(St.size() == 0) {
            return;
        }
        v.push_back(St.top());
        St.pop();
        insert(St, v);
        return;
    }
    vector<int> Reverse(stack<int> St){
        vector<int> ans;
        insert(St, ans);
        return ans;
        // return St;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends