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
    ListNode* rev(ListNode *cur) {
        ListNode *prev = NULL, *next;
        while(cur) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *temp;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        temp = rev(slow);
        
        while(temp) {
            if(temp -> val != head -> val)
                return false;
            temp = temp -> next;
            head = head -> next;
        }
        
        return true;
    }
};