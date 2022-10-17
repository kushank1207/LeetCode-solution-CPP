class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> mp(sentence.begin(), sentence.end());
        return mp.size()==26;
    }
};