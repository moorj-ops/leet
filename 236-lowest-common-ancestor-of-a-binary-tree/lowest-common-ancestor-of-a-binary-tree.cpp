/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL){
            return NULL;
        }
        //node ki value  p yah q meh se hai
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        //agar dono taraf se non null answe aa raha 
        if(leftans!=NULL && rightans!=NULL){
            return root;
        }
        else if(leftans != NULL && rightans==NULL){
            return leftans;
        }
        else if(rightans!=NULL && leftans==NULL){
            return rightans;
        }
        else{
            return NULL;
        }


    }
};