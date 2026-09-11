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
14    int dfs(TreeNode* node, long long currentSum, int targetSum,
15            unordered_map<long long, int>& prefix){
16                if(node == NULL) return NULL;
17                currentSum += node->val;
18                int count = prefix[currentSum-targetSum];
19
20                prefix[currentSum]++;
21
22                count += dfs(node->left, currentSum, targetSum, prefix);
23                count += dfs(node->right, currentSum, targetSum, prefix);
24
25                prefix[currentSum]--;
26
27                return count;
28
29            } 
30    int pathSum(TreeNode* root, int targetSum) {
31         unordered_map<long long, int> prefix;
32         prefix[0] = 1;
33
34         return dfs(root, 0, targetSum, prefix);
35
36        
37    }
38};