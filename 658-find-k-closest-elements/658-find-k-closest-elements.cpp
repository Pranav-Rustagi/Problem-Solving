class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> v;
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int j = i + 1;
        while(k--) {
            if(i < 0)
                v.push_back(arr[j++]);
            else if(j == arr.size())
                v.push_back(arr[i--]);
            else if(abs(arr[i] - x) <= abs(arr[j] - x))
                v.push_back(arr[i--]);
            else
                v.push_back(arr[j++]);
        }
        
        sort(v.begin(), v.end());
        return v;
    }
};