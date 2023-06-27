//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution {
    private:
    int arr[20001];
    
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        int sz = 0;
        struct Node *cur = head1;
        
        while(cur) {
            arr[sz++] = cur -> data;
            cur = cur -> next;
        }
        
        cur = head2;
        while(cur) {
            arr[sz++] = cur -> data;
            cur = cur -> next;
        }
        
        sort(arr, arr + sz);
        
        struct Node *res = new Node(arr[0]);
        cur = res;
        
        for(int i = 1 ; i < sz ; i++) {
            if(arr[i] == arr[i - 1])    continue;
            cur = cur -> next = new Node(arr[i]);
        }
        return res;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends