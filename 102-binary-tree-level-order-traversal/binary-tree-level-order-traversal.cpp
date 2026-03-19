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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        //level 0
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        vector<vector<int>> final_ans;
        if (root == NULL) return final_ans;
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            if(temp==NULL){
                //
                final_ans.push_back(ans);
                ans.clear();
                if(!q.empty()){
                    q.push(NULL);
                }

            }
            else{
                ans.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);


                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                
            }
            
        }

               
    return final_ans;       
    }
};