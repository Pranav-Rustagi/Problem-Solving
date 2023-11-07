class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        int time[n];
        for(int i = 0 ; i < n ; i++) {
            time[i] = ceil((dist[i] + 0.0) / speed[i]);
        }

        sort(time, time + n);

        int count = 0;
        for(int i = 0 ; i < n && i < time[i] ; i++) {
            count++;
        }

        return count;
    }
};