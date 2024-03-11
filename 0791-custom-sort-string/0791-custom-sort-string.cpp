class Solution {
public:
    string customSortString(string order, string s) {
        int arr[26], n1 = order.size();
        
        for(int i = 0 ; i < 26 ; i++) {
            arr[i] = INT_MAX;
        }
        
        for(int i = n1 - 1 ; i >= 0 ; i--) {
            arr[order[i] - 'a'] = i;
        }
        
        sort(s.begin(), s.end(), [arr](const char& a, const char& b) {
            return arr[a - 'a'] < arr[b - 'a'];
        });
        
        return s;
    }
};