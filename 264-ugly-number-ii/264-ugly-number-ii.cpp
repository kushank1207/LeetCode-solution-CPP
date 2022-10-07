class Solution {
public:
    // int nthUglyNumber(int n) {
    //     set<int> number, fix;
    //     number.insert(1);
    //     while(fix.size() != n) {
    //         int a = *number.begin();
    //         fix.insert(a);
    //         number.erase(a);
    //         number.insert(a*2);
    //         number.insert(a*3);
    //         number.insert(a*5);
    //     }
    //     return *fix.rbegin();
    // }
    
    int nthUglyNumber(int n) {
        int f[n], i2=0, i3=0, i5=0;
        f[0]=1;
        for(int i=1; i<n; i++) {
            f[i] = min(f[i2]*2, min(f[i3]*3, f[i5]*5));
            if(f[i] == f[i2]*2)
                i2++;
            if(f[i] == f[i3]*3)
                i3++;
            if(f[i] == f[i5]*5)
                i5++;
        }
        return f[n-1];
    }
};