class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int arr[50001] = {0}, count = 0, res = 0;
        arr[0] = 1;
        
        for(int el : nums) {
            count += (el & 1);
            arr[count]++;
            
            if(count >= k) {
                res += arr[count - k];
            }
        }
        
        return res;
    }
};