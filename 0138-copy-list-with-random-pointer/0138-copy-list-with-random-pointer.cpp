/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head,Node* &tail,int d)
    {
        Node* newNode = new Node(d);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        
    /*    // step 1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        
        // step 2: create a map between original node & clone node
        unordered_map<Node*,Node*> mp;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL)
        {
            mp[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        // step 3: Arranging all random pointers in clone list with help of map
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL)
        {
            cloneNode->random = mp[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        
        return cloneHead;    */
        
        
        // step 1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
    
        // step 2: Add cloneNodes in between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL)
        {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        // step 3: copy random pointer
         temp = head;
        
        while(temp!=NULL)
        {
            if(temp->next != NULL)
            {
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }
        
        // step 4: revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;
        
         while(originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
             originalNode = originalNode->next;
             
             if(originalNode != NULL)
             {
                  cloneNode->next = originalNode->next;
             }
            
             cloneNode = cloneNode->next;
        }
        
        // step 5: return ans
        return cloneHead;
    }
};