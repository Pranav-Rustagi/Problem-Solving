class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        if(n == 1)  return max(arr[0], arr[1]);

        k = min(k, n - 1);
        
        int cur = arr[0], ct = 0;
        for(int i = 1 ; i < n ; i++) {
            if(arr[i] < cur) {
                ct++;
            } else {
                cur = arr[i];
                ct = 1;
            }

            if(ct == k) {
                return cur;
            }
        }

        return cur;
    }
};