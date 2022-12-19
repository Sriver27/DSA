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
    int getLength(ListNode* head){
    ListNode* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void deleteNode(int pos, ListNode* &head){
   
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 1;
        while(cnt < pos+1)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
      
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    

    }
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == NULL) return head;
        if(head->next == NULL) return NULL;
        
        int len = getLength(head);
        //cout<<len;
        
     deleteNode(len/2,head);
        
        return head;
        
    }
};