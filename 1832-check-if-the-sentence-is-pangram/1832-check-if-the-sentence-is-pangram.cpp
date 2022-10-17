class Solution {
public:
    bool checkIfPangram(string sentence) {
        // unordered_set<char> mp(sentence.begin(), sentence.end());
        // return mp.size()==26;
        
        if(sentence.length() < 26)
            return false;
        unordered_map<char, int> mp;
        
        for(char i:sentence) {
            mp[i]++;
        }
        
        if(mp.size() >= 26) {
            return true;
        }
        else
            return false;
    }
};