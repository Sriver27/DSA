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
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        
        if(left == NULL) return right;
        
        if(right == NULL) return left;
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(left != NULL && right != NULL)
        {
            if(left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                 temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while(left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        ans = ans->next;
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        
     // Bubble Sort ------------>
        
   /*   ListNode* end ;
        ListNode* q ;
        ListNode* p ;
        
        int temp;
        
        for(end = NULL; end != head->next; end = p){
            for(p = head; p->next != end; p=p->next){
                q = p->next;
                if(p->val > q->val){
                    temp = p->val;
                    p->val = q->val;
                    q->val = temp;
                }
            }
        }
        
        return head; */
        
        // Merge Sort ---------------->
        
        // base case
        if(head == NULL || head->next == NULL) return head;
        
        // break linked list into two halves after finding mid
        ListNode* mid = middleNode(head);
        
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        // recursive calls to sort both halves
        left = sortList(left);
        right = sortList(right);
        
        // merge both left and right halves
        ListNode* result = merge(left,right);
        
        return result;
        
        
    }
};