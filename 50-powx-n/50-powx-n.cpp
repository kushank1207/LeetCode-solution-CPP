class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current = x;
        for(long long i = N; i ; i /= 2) {
            if((i % 2) == 1) {
                ans = ans * current;
            }
            current = current * current;
        }
        return ans;
    }
};