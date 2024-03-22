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
        ListNode *prev = NULL, *next;
        while(head) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode *l1 = head, *l2 = reverse(slow -> next);
        slow -> next = NULL;
        while(l1 && l2) {
            if(l1 -> val != l2 -> val) {
                return false;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        return true;
    }
};