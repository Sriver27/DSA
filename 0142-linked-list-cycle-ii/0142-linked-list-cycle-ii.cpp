/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
         ListNode* curr = head;
        map<ListNode*,bool> visit;
        
        while(curr != NULL)
        {
            if(visit.find(curr) != visit.end()) return curr;
            
            else visit[curr]=true;
            
            curr= curr->next;
        }
        
        return NULL;
        
    }
};