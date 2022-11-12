//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int arr[26] = {0};
		    int res = 0;
		    for(int i = 0, prev = -1 ; i < s.size() ; ++i) {
		        ++arr[s[i] - 'A'];
		        int maxel = *max_element(arr, arr + 26);
		        int left = accumulate(arr, arr + 26, 0) - maxel;
		        if(left > k) {
		            --arr[s[++prev] - 'A'];
		            --arr[s[i] - 'A'];
		            --i;
		        } else {
		            res = max(res, maxel + left);
		        }
		    }
		    
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends