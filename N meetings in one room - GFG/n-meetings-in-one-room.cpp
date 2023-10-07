//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    struct meeting {
        int start;
        int end;
    };
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(struct meeting m1, meeting m2) {
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        return false;
    }
    int maxMeetings(int st[], int e[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0; i<n; i++) {
            meet[i].start = st[i], meet[i].end = e[i];
        }
        sort(meet, meet+n, comp);
        
        int ans=1, limit=meet[0].end;
        for(int i=1; i<n; i++) {
            if(meet[i].start > limit) {
                limit = meet[i].end;
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends