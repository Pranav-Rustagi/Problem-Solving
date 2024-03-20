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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tlist2 = list2;
        while(tlist2 -> next) {
            tlist2 = tlist2 -> next;
        }
        
        int diff = b - a + 1;
        ListNode *preva = list1, *nextb;
        while(--a) {
            preva = preva -> next;
        }
        
        nextb = preva -> next;
        while(diff--) {
            nextb = nextb -> next;
        }
        
        preva -> next = list2;
        tlist2 -> next = nextb;
        return list1;
    }
};