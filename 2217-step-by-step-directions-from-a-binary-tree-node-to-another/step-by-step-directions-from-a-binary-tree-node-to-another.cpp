/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int start, int dest) {
        if (!root || root->val == start || root->val == dest) return root;
        TreeNode* l = findLCA(root->left, start, dest);
        TreeNode* r = findLCA(root->right, start, dest);
        if (l && r) return root;
        return l ? l : r;
    }
    
    bool findPath(TreeNode* root, int val, string& path) {
        if (!root) return false;
        if (root->val == val) return true;
        
        path.push_back('L');
        if (findPath(root->left, val, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (findPath(root->right, val, path)) return true;
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int start, int dest) {
        TreeNode* lca = findLCA(root, start, dest);
        string pathToStart, pathToDest;
        
        findPath(lca, start, pathToStart);
        findPath(lca, dest, pathToDest);
        
        for (auto& ch : pathToStart) {
            ch = 'U';
        }
        
        return pathToStart + pathToDest;
    }
};