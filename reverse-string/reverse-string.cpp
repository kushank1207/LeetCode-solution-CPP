class Solution {
public:
    void recRevString(int i, int j, vector<char>& s) {
        if(i >= j) return;
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
        recRevString(i,j,s);
    }
    void reverseString(vector<char>& s) {
        recRevString(0,s.size()-1,s);
    }
};