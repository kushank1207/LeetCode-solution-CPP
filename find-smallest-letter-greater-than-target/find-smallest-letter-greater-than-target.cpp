class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size();
        char result;
        
        while(start < end) {
            int mid = start + (end-start)/2;
            if(letters[mid] > target) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return letters[start%letters.size()];
    }
};