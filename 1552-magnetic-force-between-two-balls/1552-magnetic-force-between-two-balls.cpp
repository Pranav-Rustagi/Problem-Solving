class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n = position.size();
        int start = INT_MAX, end = position[n - 1] - position[0];
        
        for(int i = 1 ; i < n ; i++) {
            start = min(start, position[i] - position[i - 1]);
        }
        
        while(start < end) {
            int mid = (start + 1LL + end) >> 1;
            
            int count = 0, lastball = -1;
            for(int pos : position) {
                if (lastball == -1 || pos - lastball >= mid) {
                    lastball = pos;
                    count++;
                    
                    if(count > m) {
                        break;
                    }
                }
            }
            
            if (count < m) {
                end = mid - 1;
            } else {
                start = mid;
            }
        }
        
        return start;
    }
};