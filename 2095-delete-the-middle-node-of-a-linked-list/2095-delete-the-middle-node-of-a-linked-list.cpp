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
    void solve(ListNode **front, ListNode *back) {
        if(back) {
            solve(front, back -> next);
            if((*front) -> next == back) {
                (*front) -> next = back -> next;
                delete back;
            } else if((*front) -> next && (*front) -> next -> next == back) {
                delete (*front) -> next;
                (*front) -> next = back;
            } else {
                *front = (*front) -> next;
            }
        }
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) {
            head = NULL;
        }
        ListNode *dup = head;
        solve(&head, head);
        return dup;
    }
};