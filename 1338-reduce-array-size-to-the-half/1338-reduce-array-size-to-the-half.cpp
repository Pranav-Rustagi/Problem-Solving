class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto el : arr)
            ++freq[el];
        int lim = arr.size() >> 1;
        arr.clear();
        for(auto p : freq)
            arr.push_back(p.second);
        sort(arr.rbegin(), arr.rend());
        
        int res = 0;
        for(int i = 0 ; i < arr.size() && lim > 0 ; ++i, ++res)
            lim -= arr[i];
        return res;
    }
};