class Solution {
public:
    void solve(string ip,string op, set<string>& ans) {
        if(ip.size() == 0) {
            ans.insert(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        if(isalpha(ip[0])){
            op1.push_back(tolower(ip[0]));
        }
        else{
            op1.push_back(ip[0]);
        }
        if(isalpha(ip[0])){
            op2.push_back(toupper(ip[0]));
        }
        else{
            op2.push_back(ip[0]);
        }
        ip.erase(ip.begin()+0);
        solve(ip, op1, ans);
        solve(ip, op2, ans);
        
    }
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        string ip = s;
        string op;
        solve(ip, op, ans);
        vector<string> v;
        for(auto i: ans) {
            v.push_back(i);
        }
        return v;
    } 
};