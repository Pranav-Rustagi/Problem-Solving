//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pbdsTree tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update>

class Solution{
  public:
    long long int inversionCount(long long arr[], long long N) {
        long long count = 0;
        pbdsTree tree;
        while(N--) {
            tree.insert(arr[N]);
            count += tree.order_of_key(arr[N]);
        }
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends