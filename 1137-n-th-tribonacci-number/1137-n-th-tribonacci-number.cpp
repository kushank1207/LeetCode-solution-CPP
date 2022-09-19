class Solution {
public:
    int tribonacci(int n) {
        int arr[n+1];
        arr[0] = 0;
        if(n>0)
            arr[1] = 1;
        if(n>1)
            arr[2] = 1;
        
        for(int i=3; i<=n; i++) {
            arr[i] = arr[i-3]+arr[i-2]+arr[i-1];
        }
        
        return arr[n];
        // if(n<2)
        //     return n;
        
    }
};