/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
       
        int i = 0, j = 0, cur_d = 0;
        int direc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (; head != nullptr; head = head->next) {
            ans[i][j] = head->val;

            int newi = i + direc[cur_d][0], newj = j + direc[cur_d][1];
   
            if (min(newi, newj) < 0 || newi >= m || newj >= n || ans[newi][newj] != -1)
                cur_d = (cur_d + 1) % 4;

            i += direc[cur_d][0];
            j += direc[cur_d][1];
        }
        return ans;
    }
};