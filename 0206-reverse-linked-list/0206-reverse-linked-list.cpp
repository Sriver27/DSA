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
    ListNode* reverse1(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* tempHead = reverse1(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return tempHead;
    }
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
        
        // RECURSIVE_2 -------------
        return reverse1(head);
        
        // RECURSIVE_1 ----------------
       /* ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head,curr,prev);
        return head; */
       
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