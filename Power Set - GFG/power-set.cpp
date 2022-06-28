// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    void solve(string ip, string op, vector<string>& ans) {
	        if(ip.length() == 0) {
	            ans.push_back(op);
	            return;
	        }
	        string op1 = op;
	        string op2 = op;
	        
	        op2.push_back(ip[0]);
	        ip.erase(ip.begin()+0);
	        
	        solve(ip,op1,ans);
	        solve(ip,op2,ans);

	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string op = "";
		    solve(s, op, ans);
		    std::sort(ans.begin(), ans.end());
		    ans.erase(ans.begin()+0);
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends