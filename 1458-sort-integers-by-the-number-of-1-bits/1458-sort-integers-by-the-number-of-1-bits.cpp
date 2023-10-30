class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int a, const int b) {
            int dupa = a, dupb = b, c = 0;
            while(dupa) {
                c++;
                dupa &= (dupa - 1);
            }

            while(dupb) {
                c--;
                dupb &= (dupb - 1);
            }

            return c == 0 ? a < b : c < 0;
        });
        return arr;
    }
};