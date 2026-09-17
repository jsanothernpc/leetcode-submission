class Solution {
public:
    vector<TreeNode*> generate(int st, int e) {
        vector<TreeNode*> result;
        if (st > e) {
            result.push_back(nullptr);
            return result;
        }
        // Try every value as root
        for (int rootVal = st; rootVal <= e; rootVal++) {
            vector<TreeNode*> lt = generate(st, rootVal - 1);
            vector<TreeNode*> rt = generate(rootVal + 1, e);

            // Combine every left subtree with every right subtree
            for (TreeNode* l : lt) {
                for (TreeNode* r : rt) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};