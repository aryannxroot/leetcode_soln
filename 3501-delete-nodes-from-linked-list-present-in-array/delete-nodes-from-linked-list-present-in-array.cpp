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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return head;
        // Using a set for faster lookup
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        // Remove elements from the beginning of the list
        while (head && numSet.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Initialize pointers
        ListNode* current = head;
        ListNode* prev = nullptr;

        while (current) {
            if (numSet.count(current->val)) {
                // Remove the current node
                prev->next = current->next;
                delete current;
                current = prev->next; // Move to the next node
            } else {
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};