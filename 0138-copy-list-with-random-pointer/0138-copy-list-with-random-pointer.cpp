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
        
        // step 1: create a clone list
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
        
        return cloneHead;
        
    }
};