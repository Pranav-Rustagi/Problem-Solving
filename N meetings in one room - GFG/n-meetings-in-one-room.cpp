//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        vector<vector<int>> meetings;
        while(n--)
            meetings.push_back({ start[n], end[n] });
        sort(meetings.begin(), meetings.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[1] < b[1];
        });
        
        int prev = -1, count = 0;
        for(auto & meet : meetings) {
            if(prev >= meet[0])
                continue;
            else {
                count++;
                prev = meet[1];
            }
        }
        return count;
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