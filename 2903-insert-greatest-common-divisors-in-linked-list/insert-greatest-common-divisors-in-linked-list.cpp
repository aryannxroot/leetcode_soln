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
private:
    int findgcd(int a, int b)
    {
       while(a>0 && b>0){
            if(a>b)     a = a%b;
            else    b= b%a;
       }
       if(a==0)     return b;
       return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp = head;
        while (temp != nullptr && temp->next != nullptr) 
        {
            ListNode *currNode = temp;
            ListNode *nextNode = temp->next;

            ListNode *gcdNode =  new ListNode(findgcd(currNode->val,nextNode->val));

            gcdNode->next = nextNode;
            currNode ->next = gcdNode;

            temp = nextNode;
        }
        return head;
    }
};