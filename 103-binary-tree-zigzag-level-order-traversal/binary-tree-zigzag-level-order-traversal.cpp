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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> result;
      if(root==NULL){
        return result;
      }  
      queue<TreeNode*> q;
      q.push(root);
      //flag for direction
      bool leftToright=true;
      while(!q.empty()){
        //har level ko process karna hai
        //har level ka size
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            TreeNode* frontnode=q.front();
            q.pop();
            //front ki node ko pop karao
            //agar true hai toh seedhe or false hai toh reverse 

            int index=leftToright ? i : (size-i-1);
            ans[index]=frontnode->val;
            if(frontnode->left)
                q.push(frontnode->left);
            if(frontnode->right)
                q.push(frontnode->right);
        }
        //change direction
        leftToright=!leftToright;
        //push elements into result
        
        result.push_back(ans);

        
      }
      return result;
    }
};