//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        unordered_map<int, vector<pair<int, int>>> m;
        vector<int> res(4, INT_MAX);
        
        for(int i = 0 ; i < N ; ++i) {
            for(int j = i + 1 ; j < N ; ++j) {
                vector<pair<int, int>> & v = m[A[i] + A[j]];
                if(v.size() == 0 || (v.size() < 2 && v.back().first != i && v.back().second != j && v.back().second != i)) {
                    v.push_back({ i, j });
                    if(v.size() > 1) {
                        pair<int, int>& p1 = v[v.size() - 2], &p2 = v.back();
                        if((res[0] > p1.first) || (res[0] == p1.first && res[1] > p1.second) || (res[0] == p1.first && res[1] == p1.second && res[2] > p2.first) || (res[0] == p1.first && res[1] == p1.second && res[2] == p2.first && res[3] > p2.second)) {
                            res = { p1.first, p1.second, p2.first, p2.second };
                        }
                    }
                }
            }
            
            // for(auto & el : m)
            //     cout << el.first << "  " << el.second.size() << endl;
        }
        
        if(res[0] == INT_MAX) {
            return { -1, -1, -1, -1 };
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
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends