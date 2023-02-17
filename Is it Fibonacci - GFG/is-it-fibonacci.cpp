//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        long long sum = 0;
        int count = 0, i = 0, j = 0;
        while(j < N - 1) {
            sum += GeekNum[j++];
            count++;
            if(count >= K) {
                if(count > K) {
                    sum -= GeekNum[i++];
                    count--;
                }
                GeekNum.push_back(sum);
            }
        }
        
        return GeekNum.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends