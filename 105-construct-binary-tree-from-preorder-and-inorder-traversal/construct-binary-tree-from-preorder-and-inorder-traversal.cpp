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
void createMapping(vector<int> &inorder,int size,map<int,int> &p){
    for(int i=0;i<size;i++){
        //i se kya indexing assign ho jayegi inorder ke elements
        p[inorder[i]]=i;
    }
}
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int &preOrderIndex,int inOrderStart,int inOrderEnd,int size,map<int,int> &p){
        if(preOrderIndex>=size || inOrderStart>inOrderEnd){
            return NULL;
        }
        //find the element at the index
        int element=preorder[preOrderIndex++];
        //create
        TreeNode* temp=new TreeNode(element);
        //finding the position of element in inorder traversal 
        int position=p[element];
        temp->left=solve(inorder,preorder,preOrderIndex,inOrderStart,position-1,size,p);
        temp->right=solve(inorder,preorder,preOrderIndex,position+1,inOrderEnd,size,p);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        map<int,int> p;
        int n=inorder.size();
        createMapping(inorder,n,p);
        
        TreeNode* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,p);
        return ans;
    }
};