class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), s = *min_element(bloomDay.begin(), bloomDay.end()), e = 1e9;
        
        if(n < m * 1L * k) {
            return -1;
        }
        
        while(s < e) {
            int mid = (s + e) >> 1;
            int count = 0, adj = 0;
            
            for(int d : bloomDay) {
                if(d <= mid) {
                    adj++;
                } else {
                    count += (adj / k);
                    adj = 0;
                }
            }
            
            count += (adj / k);
            
            if(count < m) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        
        return s;
    }
};