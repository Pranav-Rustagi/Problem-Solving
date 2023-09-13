class Solution {
public:
    int minDeletions(string s) {
        int arr[26] = {0};
        for(char ch : s) {
            arr[ch - 'a']++;
        }

        sort(arr, arr + 26);
        int prev = INT_MAX;
        int count = 0;

        for(int i = 25 ; i >= 0 ; i--) {
            if(arr[i] < prev) {
                prev = arr[i];
            } else if(prev == 0) {
                count += arr[i];
            } else {
                count += arr[i] - prev + 1;
                prev--;
            }
        }
        return count;
    }
};