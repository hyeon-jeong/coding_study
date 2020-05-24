// Leetcode - Delete Leaves With a Given Value

class Solution {
public:
    bool removeAllLeafNodes(TreeNode* root, int target){
        bool step;
        if(!root) return false;
        
        if(root->left){
            step = removeAllLeafNodes(root->left, target);
            if(step) delete root->left, root->left = NULL;
        }
        
        if(root->right){
            step = removeAllLeafNodes(root->right, target);
            if(step) delete root->right, root->right = NULL;
        }
        
        return !root->left && !root->right && root->val == target;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(removeAllLeafNodes(root, target)){
            return NULL;
        }
        return root;
    }
};
