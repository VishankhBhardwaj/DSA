/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        TreeNode*root=nullptr;
        for (auto vec : descriptions) {
            if (nodes.find(vec[0])!=nodes.end() && nodes.find(vec[1])!=nodes.end()) {
                if (vec[2] == 1)
                    nodes[vec[0]]->left = nodes[vec[1]];
                else
                    nodes[vec[0]]->right = nodes[vec[1]];
            } else if (nodes.find(vec[0])!=nodes.end() && nodes.find(vec[1])==nodes.end()) {
                if (vec[2] == 1) {
                    TreeNode* new_node = new TreeNode(vec[1]);
                    nodes[vec[0]]->left = new_node;
                    nodes[vec[1]] = new_node;
                } else {
                    TreeNode* new_node = new TreeNode(vec[1]);
                    nodes[vec[0]]->right = new_node;
                    nodes[vec[1]] = new_node;
                }
            } else if (nodes.find(vec[0])==nodes.end() && nodes.find(vec[1])!=nodes.end()) {
                if (vec[2] == 1) {
                    TreeNode* new_node = new TreeNode(vec[0]);
                    new_node->left = nodes[vec[1]];
                    nodes[vec[0]] = new_node;
                } else {
                    TreeNode* new_node = new TreeNode(vec[0]);
                    new_node->right = nodes[vec[1]];
                    nodes[vec[0]] = new_node;
                }
            } else {
                if (vec[2] == 1) {
                    TreeNode* new_node = new TreeNode(vec[0]);
                    TreeNode* new_Node = new TreeNode(vec[1]);
                    new_node->left = new_Node;
                    nodes[vec[0]] = new_node;
                    nodes[vec[1]] = new_Node;
                } else {
                    TreeNode* new_node = new TreeNode(vec[0]);
                    TreeNode* new_Node = new TreeNode(vec[1]);
                    new_node->right = new_Node;
                    nodes[vec[0]] = new_node;
                    nodes[vec[1]] = new_Node;
                }
            }
        }
        unordered_set<int>child;
        for(auto vec:descriptions){
            child.insert(vec[1]);
        }
        for(auto pair:nodes){
            if(child.find(pair.first)==child.end()){
                root=pair.second;
                break;
            }
        }
        return root;
    }
};

//more efficient code
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> childVals;

        for (auto& desc : descriptions) {
            int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];

            // Create parent node if it doesn't exist
            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }

            // Create child node if it doesn't exist
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }

            // Connect child to parent
            if (isLeft)
                nodes[parentVal]->left = nodes[childVal];
            else
                nodes[parentVal]->right = nodes[childVal];

            // Track that this value is a child
            childVals.insert(childVal);
        }

        // Find the root (node that is not any child)
        for (auto& [val, node] : nodes) {
            if (childVals.find(val) == childVals.end()) {
                return node;
            }
        }

        return nullptr; // fallback, should never hit
    }
};
