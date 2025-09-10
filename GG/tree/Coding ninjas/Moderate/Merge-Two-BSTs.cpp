/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
vector<int>merge(vector<int>&a,vector<int>&b){
    vector<int>ans(a.size()+b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
    }
    while(j<b.size()){
        ans[k++]=b[j++];
    }
    return ans;
}
void inorder(TreeNode*root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
// TreeNode* inorderToBST(int s,int e,vector<int>&in){
//     if(s>e){
//         return NULL;
//     }
//     int mid=(s+e)/2;
//     TreeNode* root= new TreeNode(in[mid]);
//     //rest rescursion wiil see
//     root->left=inorderToBST(s,mid-1,in);
//     root->right=inorderToBST(mid+1,e,in);
//     return root;
// }    ye code isloye agar tree return krna hota but hume vector return krna hai to seedha merged array return krdi
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int>inorder1;
    vector<int>inorder2;
    //call inorder of two tree
    inorder(root1,inorder1);
    inorder(root2,inorder2);

    //merge two list
    return merge(inorder1,inorder2);
    // int s=0;
    // int e=mergedlist.size()-1;
    // return inorderToBST(s,e,mergedlist);
}