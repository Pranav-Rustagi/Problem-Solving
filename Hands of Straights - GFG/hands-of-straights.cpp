//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int gs, vector<int> &hand) {
        if(N % gs) {
            return false;
        }
        
        multiset<int> m(hand.begin(), hand.end());
        for(int el : m) {
            for(int i = 1 ; i < gs ; i++) {
                if(m.count(el + i)) {
                    m.erase(m.find(el + i));
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends