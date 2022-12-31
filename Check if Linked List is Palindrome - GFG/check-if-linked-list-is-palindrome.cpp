//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* reverseLL(Node *head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;
        
        while(curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    Node* middleNode(Node* head) {
        /*Jab tak fast pointer end mein pahuchega tab tak slow mid tak hi pahuchega kyoki,
        fast pointer head node se start kar 2x mei move kar rh hai and slow vhi sirf 1x mein*/
        
        if(head == NULL) return head;
        
        if(head->next == NULL) return head; // if the list has just 1 node, then vhi na mid hoga
        Node* fast = head;
        Node* slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head == NULL || head->next == NULL) return true;
        
        Node* mid = middleNode(head);
        Node* last = reverseLL(mid);
        
        Node* curr = head;
        
        while(last != NULL)
        {
            if(last->data != curr->data) return false;
            
            last = last->next; 
            curr = curr->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends