class Solution {
public:
    TreeNode* balanceroot(vector<int>&v,int st, int e){
        if(st > e) return NULL;
        int mid = (st+e)/2;
        TreeNode* newroot = new TreeNode(v[mid]);
        newroot->left = balanceroot(v,st,mid-1);
        newroot->right = balanceroot(v,mid+1,e);
        return newroot;
    }
    void inorder(TreeNode *root, vector<int>&v){
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        return balanceroot(v,0,v.size()-1);
    }
};