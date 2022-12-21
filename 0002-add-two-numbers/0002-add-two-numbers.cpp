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
    
    void insertAtTail(ListNode* &head, ListNode* &tail, int val)
    {
        ListNode* temp = new ListNode(val);
        
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    ListNode* add(ListNode* l1,ListNode* l2)
    {
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(l1 != NULL || l2!=NULL || carry !=0)
        {
            int val1 = 0;
            if(l1 != NULL)
                val1 = l1->val;
            
              int val2 = 0;
            if(l2 != NULL)
                val2 = l2->val;
            
            int sum = carry + val1 +val2;
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum/10;
            
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        
        return ansHead;
    }
    
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        
        while(curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Step 1 : reverse both lists
        // l1 = reverseLL(l1);
        // l2 = reverseLL(l2);
        
        // Step 2 : add both LL
        ListNode* ans = add(l1,l2);
        
        // Step 3: again reverse ans list and return the result
        //ans = reverseLL(ans);
        
        return ans;
        
    }
};