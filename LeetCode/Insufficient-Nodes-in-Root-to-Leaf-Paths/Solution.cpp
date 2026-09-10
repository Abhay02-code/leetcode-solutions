1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* sufficientSubset(TreeNode* root, int limit) {
15        if(root == NULL) return NULL;
16        limit = limit - root->val;
17        if(root->left == NULL && root->right == NULL){
18            if(limit>0) return NULL;
19
20            return root;
21        }
22        
23
24        root->left = sufficientSubset(root->left, limit);
25        root->right = sufficientSubset(root->right, limit);
26
27        if(root->left == NULL && root->right == NULL) return NULL;
28
29        return root;
30
31        
32    }
33};