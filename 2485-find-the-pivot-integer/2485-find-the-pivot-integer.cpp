class Solution {
public:
    int pivotInteger(int n) {
        int arr[n + 1];
        arr[0] = 0;
        for(int i = 1 ; i <= n ; i++) {
            arr[i] = i + arr[i - 1];
        }
        
        for(int i = 1 ; i <= n ; i++) {
            int f = arr[i];
            int s = arr[n] - arr[i - 1];
            if(f == s) {
                return i;
            }
        }
        
        return -1;
    }
};