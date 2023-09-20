class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        cout << slow << " " << fast << endl;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            cout << slow << " " << fast << endl;
        }

        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};