class Solution {
public:
    int post_idx = 0;  // ����������������λ��
    unordered_map<int, int> index;  // ���ڿ��ٶ�λ root ��λ��

    TreeNode* helper(int left, int right, vector<int>& inorder, vector<int>& postorder) {
        if (left > right) return nullptr;

        int rootVal = postorder[post_idx]; // ͷ�ڵ����ֵ

        int inIndex = index[rootVal];      // ͨ��ͷ�ڵ����ֵȷ���������λ��

        post_idx--;
        TreeNode* root = new TreeNode(rootVal); // ����ڵ�
        root->right = helper(inIndex + 1, right, inorder, postorder); // �ȵݹ���������
        root->left = helper(left, inIndex - 1, inorder, postorder);  //�ٵݹ�����������Ϊ post_id ��������ݼ���
        return root; // �������ڵ�
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        post_idx = size - 1;
        for (int i = 0; i < size; i++) {
            index[inorder[i]] = i; // Ԫ����map
        }
        return helper(0, size - 1, inorder, postorder); // ���� ��
    }
};