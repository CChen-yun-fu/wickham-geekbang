class Node {
public:
    int l;
    int r;
    int h;
    Node* left;
    Node* right;
    Node(int left1, int right1, int height) {
        this->l = left1;
        this->r = right1;
        this->h = height;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int>ans;
        int maxH = 0;
        Node* root = NULL;
        for (vector position : positions) {
            int l = position[0]; // 左坐标
            int r = position[1] + position[0]; //右坐标
            int edge = position[1]; // 边长
            int curH = querry(root, l, r); // 当前区间的最高高度
            root = insert(root, l, r, edge + curH);
            maxH = max(maxH, curH + edge);

            ans.push_back(maxH);
        }
        return ans;
    }
private:
    Node* insert(Node* root, int l, int r, int h) {
        if (root == NULL) return new Node(l, r, h);
        if (l <= root->l) root->left = insert(root->left, l, r, h);
        else root->right = insert(root->right, l, r, h);

        return root;
    }
    int querry(Node* root, int l, int r) {
        if (root == NULL) return 0;
        int curH = 0;
        if (!(r <= root->l || root->r <= l))
            curH = root->h;
        curH = max(curH, querry(root->left, l, r));
        if (r > root->l)
            curH = max(curH, querry(root->right, l, r));
        return curH;
    }
};