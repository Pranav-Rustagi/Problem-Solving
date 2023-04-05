//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        vector<bool> hash(1000001, false);
        int count = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < N ; i++) {
            if(hash[arr[i]]) {
                ++count;
            } else {
                if(i + 1 < N && arr[i] == arr[i + 1]) {
                    ++count;
                }
                
                for(int j = arr[i] ; j <= arr[N - 1] ; j += arr[i]) {
                    hash[j] = true;
                }
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends