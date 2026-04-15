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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int len = 0;
        // ListNode* temp = head;
        // while(temp) {
        //     temp = temp->next;
        //     len++;
        // }
        // int steps = len - n;
        ListNode* fast = head;
        while(n > 0) {
            fast = fast->next;
            n--;
        }
        if(!fast)
            return head->next;
        ListNode* slow = head;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next)
            slow->next = slow->next->next;
        return head;
    }
};
