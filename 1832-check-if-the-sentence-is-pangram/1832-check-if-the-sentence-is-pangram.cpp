class Solution {
public:
    bool checkIfPangram(string sentence) {
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