class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=0, j=num/2;
        if(num == 1){
            return true;
        }
        while(i<=j) {
            int mid = i + (j-i)/2;
            long num1 = (long)mid*mid;
            if(num1 == num) {
                return true;
            }
            else if(num1 > num) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        return false;
    }
};