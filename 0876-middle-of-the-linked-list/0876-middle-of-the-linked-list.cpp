/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head) {
        int count = 0;
        while(head) {
            ++count;
            head = head -> next;
        }
        return count;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = (getLen(head) >> 1);
        while(n--){
            head = head -> next;
        }
        return head;
    }
};