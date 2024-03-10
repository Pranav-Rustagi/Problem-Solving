class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size();
        
        vector<int> res;
        while(i1 < n1 && i2 < n2) {
            if(nums1[i1] == nums2[i2]) {
                if(res.empty() || res.back() != nums1[i1]) {
                    res.push_back(nums1[i1]);
                }
                i1++;
                i2++;
            } else if(nums1[i1] < nums2[i2]) {
                i1++;
            } else {
                i2++;
            }
        }
        
        return res;
    }
};