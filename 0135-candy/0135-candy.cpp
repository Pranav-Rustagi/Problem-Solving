class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        pair<int, int> arr[n];
        for(int i = 0 ; i < n ; i++) {
            arr[i].first = ratings[i];
            arr[i].second = i;
        }

        sort(arr, arr + n);

        int count = 0;
        int v[n];
        memset(v, -1, sizeof(v));

        for(int i = 0 ; i < n ; i++) {
            int ind = arr[i].second;
            bool vl = ind - 1 >= 0;
            bool vr = ind + 1 < n;

            int lim1 = vl && ratings[ind] > ratings[ind - 1] ? max(1, v[arr[i].second - 1]) : 0;
            int lim2 = vr && ratings[ind] > ratings[ind + 1] ? max(1, v[arr[i].second + 1]) : 0;
            count += v[arr[i].second] = 1 + max(lim1, lim2);
        }
        return count;
    }
};