/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return NULL;

        Node* cur = head;
        while(cur) {
            Node *next = cur -> next;
            cur -> next = new Node(cur -> val);
            cur = cur -> next -> next = next;
        }

        cur = head;
        while(cur) {
            if(cur -> random) {
                cur -> next -> random = cur -> random -> next;
            }
            cur = cur -> next -> next;
        }
        
        Node *res = head -> next, *resh = head -> next;
        while(head) {
            head = head -> next = res ? res -> next : NULL;
            res = res -> next = head ? head -> next : NULL;
        }
        return resh;
    }
};