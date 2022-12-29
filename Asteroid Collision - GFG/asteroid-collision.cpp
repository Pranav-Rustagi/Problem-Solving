//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int> res;
        for(int i = 0 ; i < asteroids.size() ; i++) {
            int a = asteroids[i];
            if(res.size() == 0 || a >= 0 || res.back() < 0) {
                res.push_back(a);
            } else if(res.back() == -a) {
                res.pop_back();
            }
            else if(res.back() >= 0 && res.back() < -a){
                res.pop_back();
                --i;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends