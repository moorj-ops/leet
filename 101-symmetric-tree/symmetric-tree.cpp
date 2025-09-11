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
    bool checksymmetric(TreeNode* root1, TreeNode* root2){
        if(root1==NULL || root2==NULL){
            return root1==root2;
        }
        bool checkroot=(root1->val==root2->val);
        bool leftcheck=(checksymmetric(root1->left,root2->right));
        bool rightcheck=(checksymmetric(root1->right,root2->left));
        
        return (checkroot&&leftcheck&&rightcheck);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return checksymmetric(root->left,root->right);
        
    }
};