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
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;

    }
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->right); // µİ¹éÓÒ×ÓÊ÷
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
    int pre = 0;
};