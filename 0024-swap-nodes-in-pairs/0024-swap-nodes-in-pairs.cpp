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
    ListNode* _reverseKGroup(ListNode* head, int size, int k)
    {
        
        //base case
        if(head == NULL || size < k) return head;
        
        //Step-1 : Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        
        int count = 0;
        
        while(curr != NULL && count < k)
        {
            nextNode = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nextNode;
            
            count++;
        }
        
        //Step-2: Recursion dekhlega aage ka part
       
            head->next = _reverseKGroup(nextNode,size-k,k);
        
        
        //REturn head of reversed list
        return prev;
        
    }
    
    int getLength(ListNode* head)
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    ListNode* swapPairs(ListNode* head) {
        
        int size = getLength(head);
        return _reverseKGroup(head,size,2);
        
    }
};