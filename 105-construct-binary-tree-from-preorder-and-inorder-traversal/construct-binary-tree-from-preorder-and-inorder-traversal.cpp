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
int findPosition(vector<int> &inorder,int element,int size){
    for(int i=0;i<size;i++){
        if(inorder[i]==element)
            return i;
    }return -1;
}
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int &preOrderIndex,int inOrderStart,int inOrderEnd,int size){
        if(preOrderIndex>=size || inOrderStart>inOrderEnd){
            return NULL;
        }
        //find the element at the index
        int element=preorder[preOrderIndex++];
        //create
        TreeNode* temp=new TreeNode(element);
        //finding the position of element in inorder traversal 
        int position=findPosition(inorder,element,size);
        temp->left=solve(inorder,preorder,preOrderIndex,inOrderStart,position-1,size);
        temp->right=solve(inorder,preorder,preOrderIndex,position+1,inOrderEnd,size);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int n=inorder.size();
        TreeNode* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n);
        return ans;
    }
};