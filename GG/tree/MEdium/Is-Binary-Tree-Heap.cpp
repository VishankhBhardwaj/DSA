// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  int countNode(Node*root){
      if(root==NULL) return 0;
      int ans = 1+countNode(root->left) + countNode(root->right);
      return ans;
  }
  bool isMaxOrder(Node*root){
      if(!root->left && !root->right) return true;
      if(!root->right){
          return root->data>root->left->data;
      }
      else{
          bool left = isMaxOrder(root->left);
          bool right = isMaxOrder(root->right);
          if(left && right && (root->data>root->left->data && root->data>root->right->data)){
          
              return true;
          }
          return false;
      }
  }
  bool isCBT(Node*root,int i,int nodeCount){
      if(root==NULL) return true;
      if(i>=nodeCount) return false;
      else{
          bool left = isCBT(root->left,2 * i + 1,nodeCount);
          bool right = isCBT(root->right,2 * i + 2,nodeCount);
          return left && right;
      }
  }
    bool isHeap(Node* tree) {
        // code here
        int i=0;
        int nodeCount = countNode(tree);
        if(isCBT(tree,i,nodeCount) && isMaxOrder(tree)){
            return true;
        }
        return false;
    }
};