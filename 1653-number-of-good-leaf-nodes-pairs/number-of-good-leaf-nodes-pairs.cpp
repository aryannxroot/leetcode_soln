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
int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int &result) {
        if (!node) return {};

        if (!node->left && !node->right) return {1};

        vector<int> left = dfs(node->left, distance, result);
        vector<int> right = dfs(node->right, distance, result);

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }

        vector<int> current;
        for (int l : left) {
            if (l + 1 <= distance) current.push_back(l + 1);
        }
        for (int r : right) {
            if (r + 1 <= distance) current.push_back(r + 1);
        }

        return current;
        
    }
};