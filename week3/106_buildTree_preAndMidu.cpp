class Solution {
public:
    int post_idx = 0;  // 后续遍历数组最后的位置
    unordered_map<int, int> index;  // 用于快速定位 root 的位置

    TreeNode* helper(int left, int right, vector<int>& inorder, vector<int>& postorder) {
        if (left > right) return nullptr;

        int rootVal = postorder[post_idx]; // 头节点的数值

        int inIndex = index[rootVal];      // 通过头节点的数值确定在中序的位置

        post_idx--;
        TreeNode* root = new TreeNode(rootVal); // 创造节点
        root->right = helper(inIndex + 1, right, inorder, postorder); // 先递归完右子树
        root->left = helper(left, inIndex - 1, inorder, postorder);  //再递归左子树，因为 post_id 从右向左递减的
        return root; // 返回树节点
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        post_idx = size - 1;
        for (int i = 0; i < size; i++) {
            index[inorder[i]] = i; // 元素入map
        }
        return helper(0, size - 1, inorder, postorder); // 构造 树
    }
};