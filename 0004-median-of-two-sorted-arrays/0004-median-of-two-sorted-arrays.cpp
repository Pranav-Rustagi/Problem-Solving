class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = n1 + n2 + 1;
        int rlim = (total >> 1);
        
        int s = 0, e = n1;
        while(s <= e) {
            int cut1 = (s + e) >> 1;
            int cut2 =  rlim - cut1;

            int left1 = cut1 > 0 ? nums1[cut1 - 1] : INT_MIN;
            int left2 = cut2 > 0 ? nums2[cut2 - 1] : INT_MIN;
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(left1 > right2) {
                e = cut1 - 1;
            } else if(left2 > right1) {
                s = cut1 + 1;
            } else {
                if(total & 1) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                return max(left1, left2);

            }
        }

        return -1;
    }
};