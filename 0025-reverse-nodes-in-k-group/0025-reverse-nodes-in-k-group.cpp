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
        // base cases
        if(head == NULL || size < k) return head; /* size : LL size, k: group size, and if size<k there is no point. */
        
        // reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        int count = 1;
        
        while(curr != NULL && count <= k)
        {
            nextNode = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }
        
        // aage ka part recursion dekh lega
        if(nextNode != NULL)
        {
            head->next = _reverseKGroup(nextNode, size-k, k );
        }
        
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int size = getLength(head);
        return _reverseKGroup(head, size, k);
        
    }
};