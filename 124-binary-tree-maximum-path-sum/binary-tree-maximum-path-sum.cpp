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
    int findmaxpathsum(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        //calculate dono side sum
        int leftmaxsum=max(0,findmaxpathsum(root->left,maxi));
        int rightmaxsum=max(0,findmaxpathsum(root->right,maxi));
        maxi=max(maxi,leftmaxsum+rightmaxsum+root->val);
        //but return single path , either elft or right
        return max(leftmaxsum,rightmaxsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findmaxpathsum(root,maxi);
        return maxi;
    }
};