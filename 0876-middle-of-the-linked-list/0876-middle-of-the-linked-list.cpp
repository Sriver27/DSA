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
    ListNode* middleNode(ListNode* head) {
        /*Jab tak fast pointer end mein pahuchega tab tak slow mid tak hi pahuchega kyoki, fast pointer head node se start kar 2x mei move kar rh hai and slow vhi sirf 1x mein*/
        
        if(head == NULL) return head;
        
        if(head->next == NULL) return head; // if the list has just 1 node, then vhi na mid hoga
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
};