//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> res;
        int minel = *min_element(arr.begin(), arr.end());
        
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == minel) {
                res.push_back(-1);
                continue;
            }
            
            int j1 = i - 1, j2 = i + 1;
            while(j1 >= 0 && arr[j1] >= arr[i]) {
                j1--;
            }
            
            while(j2 < n && arr[i] <= arr[j2]) {
                j2++;
            }
            
            if(j1 < 0) {
                res.push_back(j2);
            } else if(j2 == n) {
                res.push_back(j1);
            } else if(i - j1 == j2 - i) {
                if(arr[j1] <= arr[j2]) {
                    res.push_back(j1);
                } else {
                    res.push_back(j2);
                }
            }
            else {
                if(i - j1 < j2 - i) {
                    res.push_back(j1);
                } else {
                    res.push_back(j2);
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends