//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

void markParents(Node* root, unordered_map<Node*, Node*> &parent_track)
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        if(curr->left) {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

Node* findNode(Node* root, int target) {
    if (root == nullptr) {
        return nullptr;  // If the tree is empty or the target is not found.
    }

    if (root->data == target) {
        return root;  // If the current node has the target value.
    }

    // Recursively search in the left and right subtrees.
    Node* leftResult = findNode(root->left, target);
    Node* rightResult = findNode(root->right, target);

    // Return the result from either subtree (if found).
    if (leftResult != nullptr) {
        return leftResult;
    } else {
        return rightResult;
    }
}


public:

    /* 
    Mark each node to its parent to traverse upwards
    We will do a BFS traversal starting from the target node
    As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
    when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result
    */


    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> parent_track; // node->parent
        markParents(root,parent_track);
        
     unordered_map<Node*, bool> visited;
queue<Node*> q;

Node* targetNode = findNode(root, target);

q.push(targetNode);

visited[targetNode] = true; // Mark the target node as visited
int curr_level = 0;

       /*Radially traversing on top and bottom side*/ 
        while(!q.empty()) /* Second BFS goes to k level from target node and using our hashtable info */
        {
            int size = q.size();
            
            if(curr_level++ == k) break;
            
            for(int i = 0; i<size; i++)
            {
                Node* curr = q.front(); q.pop();
                
                if(curr -> left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                 if(curr -> right && !visited[curr->right]){
                      q.push(curr->right);
                      visited[curr->right] = true;
                 }
                 
                 if(parent_track[curr] && !visited[parent_track[curr]])
                 {
                     q.push(parent_track[curr]);
                     visited[parent_track[curr]] = true;
                 }
            }
        }
        
        vector<int> res;
        while(!q.empty())
        {
            Node* curr = q.front(); q.pop();
            res.push_back(curr->data);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends