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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        if (k == 1)
            return head;
        ListNode* temp = head;
        while(cnt < k-1 && temp && temp->next) {
            temp = temp->next;
            cnt++;
        }
        if (cnt < k-1)
            return head;
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        head = reverseList(head);
        temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = reverseKGroup(newHead, k);
        cout<<head->val<<endl;
        cout<<temp->val<<endl;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
