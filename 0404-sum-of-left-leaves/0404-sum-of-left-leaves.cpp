/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,int &sum)
    {
        if(root == NULL) return;

        inorder(root->left,sum);
        if(root->left != NULL && root->left->right==NULL &&  root->left->left==NULL)                    sum+=root->left->val; 
        inorder(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0;
        if(root == NULL) return 0;
        
        inorder(root,sum);
        return sum;
        
    }
};