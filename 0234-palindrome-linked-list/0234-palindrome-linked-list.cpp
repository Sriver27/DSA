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
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        
        while(curr != NULL)
        {
            nextNode = curr -> next;
            curr-> next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
        
    }
    
    ListNode* middleNode(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head -> next == NULL) return true;
        
        ListNode* middle = middleNode(head);
        ListNode* last = reverseList(middle);
        
        ListNode* curr = head;
        
        while(last != NULL)
        {
            if(last->val != curr->val) return false;
            
            last = last->next;
            curr = curr->next;
        }
        
        return true;
        
    }
};