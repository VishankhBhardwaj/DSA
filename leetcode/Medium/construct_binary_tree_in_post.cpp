class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder,
                              int postStart, int postEnd, int inStart,
                              int inEnd, map<int, int>& Inorder_map) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = Inorder_map[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(postorder, inorder, postStart,
                                     postStart + numsLeft - 1, inStart,
                                     inRoot - 1, Inorder_map);

        root->right =
            buildTreeHelper(postorder, inorder, postStart + numsLeft,
                            postEnd - 1, inRoot + 1, inEnd, Inorder_map);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> Inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            Inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(postorder, inorder, 0, postorder.size() - 1, 0,
                               inorder.size() - 1, Inorder_map);
    }
};
Flatten Binary Tree to Linked List