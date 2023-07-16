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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val > list2-> val) swap(list1,list2); // dhyaan mein rakhna list1 hamesha choti rehni chahiye...
        
        ListNode* res = list1;
        
        while(list1 != NULL && list2 != NULL)
        {
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            
            /* Jab paya gya ki list2 mei value choti mili h toh simply link ko point kro usko aur lists swap kardo */
            temp->next = list2;
            swap(list1, list2); // swapping needs to be done for every iteration
        }
        
        return res;
        
    }
};