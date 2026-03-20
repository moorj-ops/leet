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
    int findposition(vector<int>& inorder,int element,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int>& inorder, vector<int>& preorder,int &index,int inorderstart,int inorderend,int n){
        //base case
        if(index>=n || inorderstart>inorderend ){
            return NULL;

        }
        int element=preorder[index++];
        TreeNode* root =new TreeNode(element);
        int position=findposition(inorder,element,n);
        root->left=solve(inorder, preorder,index,inorderstart,position -1,n);
        root->right=solve(inorder, preorder,index,position+1,inorderend,n);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=preorder.size();
        TreeNode * ans=solve(inorder,preorder,index,0,n-1,n);
        return ans;
    }
};