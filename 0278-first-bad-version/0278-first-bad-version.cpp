// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=0, j=n;
        int ans=-1;
        while(i<=j) {
            int mid = i+(j-i)/2;
            if(isBadVersion(mid)) {
                j=mid-1;
                ans = mid;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};