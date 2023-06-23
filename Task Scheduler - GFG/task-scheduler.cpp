//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        int arr[26] = {0}, maxF = 0;
        
        for(char ch : tasks)
            maxF = max(maxF, ++arr[ch - 'A']);
        
        int maxFC = 0;
        for(int i = 0 ; i < 26 ; i++)
            if(arr[i] == maxF)
                maxFC++;
        
        return max(N, (maxF - 1) * (K + 1) + maxFC);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends