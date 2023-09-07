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
    ListNode* reverse(ListNode* head) {
        ListNode *cur = head, *prev = NULL, *next;
        while(cur) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL, *cur = head;
        while(left > 1) {
            prev = cur;
            cur = cur -> next;
            left--;
            right--;
        }

        ListNode *fe = cur;

        while(right > 1) {
            right--;
            cur = cur -> next;
        }

        ListNode *next = cur -> next;
        cur -> next = NULL;

        ListNode *mid = reverse(fe);

        fe -> next = next;
        if(prev) {
            prev -> next = mid;
        } else {
            head = mid;
        }
        return head;
    }
};