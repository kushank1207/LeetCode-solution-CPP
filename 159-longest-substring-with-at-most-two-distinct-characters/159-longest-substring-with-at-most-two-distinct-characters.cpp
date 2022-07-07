class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int i=0, j=0;
        int mx = INT_MIN;
        while(j < s.length()) {
            mp[s[j]]++;
            
            if(mp.size() <= 2) {
                mx = max(mx, j-i+1);
            } else if(mp.size() > 2) {
                while(mp.size() > 2) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};