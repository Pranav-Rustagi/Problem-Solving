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
        sort(arr.begin(), arr.end());
        
        int res = 0;
        while(arr.size() && lim > 0) {
            lim -= arr.back();
            arr.pop_back();
            ++res;
        }
        
        return res;
    }
};