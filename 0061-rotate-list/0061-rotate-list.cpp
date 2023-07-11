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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //base cases
        if(head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode* temp = head;
        int size = 1;
        
        while(temp->next != NULL)
        {
            size++;
            temp = temp->next;
        }
        
        // handle size
        k = k % size;
        // Loop kardena h....
        temp-> next = head;
        
        while(--size >= k)
        {
            temp = temp->next;
        }
        
        ListNode* first = temp->next; /* Yahi toh first node hai hamare rotated list ki */
        temp->next = NULL;
        
        
        return first;
        
    }
};