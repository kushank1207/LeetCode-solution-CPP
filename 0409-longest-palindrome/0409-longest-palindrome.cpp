class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(char i : s)
            mp[i]++;
        
        int length=0, carry=0;
        for(auto i : mp) {
            if(i.second%2 == 1) {
                carry=1;
                length += i.second-1;
            } else {
                length += i.second;
            }
        }
        
        return length+carry;
    }
};