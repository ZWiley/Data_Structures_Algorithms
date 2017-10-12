//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
class Solution {
public:
    int run(TreeNode *root) {
        if (!root)
            return 0;
        
        int l = run(root->left);
        int r = run(root->right);
        if (l == 0 || r == 0)
        {
            return 1+l+r;   
        }
        return 1+min(l,r);
    }
};