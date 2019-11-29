/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (73.35%)
 * Likes:    337
 * Dislikes: 13
 * Total Accepted:    22.5K
 * Total Submissions: 30.7K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
 * 
 * 
 */
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> idx;idx.assign(preorder.size()+10,preorder.size());
        stack<int> pq;
        TreeNode* head = nullptr;
        for(int i = 0;i<preorder.size();i++){
            if(pq.empty()){
                pq.emplace(i);
                continue;
            }
            while(!pq.empty() && preorder[i] > preorder[pq.top()]){
                idx[pq.top()] = i;
                pq.pop();
            }
            pq.emplace(i);
        }
        function<TreeNode*(int,int)> rec = [&](int tl,int tr){
            if(tl < tr){
                TreeNode* temp = new TreeNode(preorder[tl]);
                temp->left = rec(tl+1,idx[tl]-1);
                temp->right = rec(idx[tl],tr);
                return temp;
            }else if(tl == tr){
                TreeNode* temp = new TreeNode(preorder[tl]);
                return temp;
            }
            TreeNode* temp = nullptr;
            return temp;
        };
        head = rec(0,preorder.size()-1);
        return head;
    }
};

