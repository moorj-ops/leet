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
//     void inorderHelper(TreeNode* root, vector<int>& ans) {
//         if(root == nullptr) return;

//         inorderHelper(root->left, ans);
//         ans.push_back(root->val);
//         inorderHelper(root->right, ans);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inorderHelper(root, ans);
//         return ans;
//     }
// };

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(root==NULL){
    //         return ans;
    //     }
    //     inorderTraversal(root->left);
    //     ans.push_back(root->val);
    //     inorderTraversal(root->right);

    //     return ans;

        
    // }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //finding the predecessor of the left
                //firts go left
                TreeNode* prev=curr->left;
                //then go to right , until right is null
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                } 
                //if predecessor right is null
                //make a connection to curr
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    //if the right is not null then break the connection
                    prev->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }

            }
        }
        return res;
    }



    };