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
    void solve(ListNode** head, ListNode* prev, int& n) {
        if(*head) {
            solve(&((*head) -> next), *head, n);
            if(--n == 0) {
                ListNode *temp = *head;
                if(prev) {
                    prev -> next = (*head) -> next;
                } else {
                    *head = (*head) -> next;
                }
                delete temp;
            }
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        solve(&head, NULL, n);
        return head;
    }
};