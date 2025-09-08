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
    pair<bool,int> isBalancedfast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> leftans=isBalancedfast(root->left);
        pair<bool,int> rightans=isBalancedfast(root->right);
        bool diff=abs(leftans.second-rightans.second)<=1;//height of leftsubtree - rightsubtree
        pair<bool,int> ans;
        //ans ke second part meh height
        ans.second=max(leftans.second,rightans.second)+1;
        if(leftans.first && rightans.first && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedfast(root).first;
    }
};