class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n];
        memset(arr, 0, sizeof(arr));
        
        for(auto t : trust) {
            arr[t[0] - 1] = -1;
            if(arr[t[1] - 1] != -1) {
                arr[t[1] - 1]++;
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == n - 1) {
                return i + 1;
            }
        }
        
        return -1;
    }
};