// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree{1,#,2,3},

//    1
//     \
//      2
//     /
//    3


// return[1,2,3].

// Note: Recursive solution is trivial, could you do it iteratively? 
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> s;
        if (root == NULL)
        {
            return res;   
        }
        s.push(root);
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right != NULL)
                s.push(cur->right);
            if (cur->left != NULL)
                s.push(cur->left);
        }
        return res;
    }
}; 