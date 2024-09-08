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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);

        int size = 0;
        ListNode *curr = head ;
        while(curr != nullptr)
        {
            curr = curr->next;
            size++;
        }

        int partSize = size/k;
        int numRemainParts = size%k;

        curr = head;
        ListNode *prev = curr;
        for(int i = 0;i<k;i++)
        {
            ListNode *newPart = curr;
            int currSize = partSize;
            if(numRemainParts>0)
            {
                numRemainParts--;
                currSize++;
            }

            int j = 0;
            while(j<currSize)
            {
                prev = curr;
                if(curr != nullptr){
                    curr = curr->next;
                }
                j++;
            }

            if(prev != nullptr)
            {
                prev->next = nullptr;
            }
            ans[i] = newPart;
        }
        return ans;
    }
};