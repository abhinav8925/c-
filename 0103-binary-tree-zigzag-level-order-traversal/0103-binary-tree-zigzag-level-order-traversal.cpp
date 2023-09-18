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

 // Problem Link -> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>result;
        if(root ==NULL){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>ans(size);
            for(int i = 0; i<size; i++){
                TreeNode*frontNode = q.front ();
                q.pop();
                
                int index= LeftToRight ? i : size-i-1;
                ans[index] = frontNode->val;
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
            LeftToRight=! LeftToRight;
            result.push_back(ans);
        }
        return result;

    }
};