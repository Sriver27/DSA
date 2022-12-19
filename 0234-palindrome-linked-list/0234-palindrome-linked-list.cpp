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
    void reverse(ListNode* &head, ListNode* &curr, ListNode* &prev)
    {
        //base case
        if(curr == NULL)
        {
            head = prev;
            return;
        }
        
        ListNode* forward = curr->next;
        reverse(head,forward,curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        
        // RECURSIVE ----------------
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head,curr,prev);
        return head;
       
       // ITERATIVE--------------
        /* ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        
        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
        */
        
    }
};