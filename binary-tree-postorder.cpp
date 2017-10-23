// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree{1,#,2,3},

//    1
//     \
//      2
//     /
//    3


// return[3,2,1].

// Note: Recursive solution is trivial, could you do it iteratively?
//// 巧妙的方法：前序遍历 根->左->右 变成 根->右->左 结果再reverse一下
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        
        stack<TreeNode*> st;
        st.push(root);
        while (st.size())
        {
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            if(temp->left)
                st.push(temp->left);
            if(temp->right)
                st.push(temp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};