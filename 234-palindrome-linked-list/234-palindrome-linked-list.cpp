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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *temp;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        fast = NULL;
        while(slow) {
            temp = slow -> next;
            slow -> next = fast;
            fast = slow;
            slow = temp;
        }
        
        while(fast) {
            if(fast -> val != head -> val)
                return false;
            fast = fast -> next;
            head = head -> next;
        }
        
        return true;
    }
};