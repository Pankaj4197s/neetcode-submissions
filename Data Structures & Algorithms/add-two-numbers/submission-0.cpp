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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(l1 && l2) {
            int a = l1->val;
            int b = l2->val;
            int sum = a + b + carry;
            int value = sum%10;
            carry = sum/10;
            cout<<carry<<endl;
            ListNode* curr = new ListNode(value);
            temp->next = curr;
            temp = curr;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int a = l1->val;
            int sum = a + carry;
            int value = sum%10;
            carry = sum/10;
            ListNode* curr = new ListNode(value);
            temp->next = curr;
            temp = curr;
            l1 = l1->next;
        }

        while(l2) {
            int a = l2->val;
            int sum = a + carry;
            int value = sum%10;
            carry = sum/10;
            ListNode* curr = new ListNode(value);
            temp->next = curr;
            temp = curr;
            l2 = l2->next;
        }

        if(carry > 0) {
            ListNode* curr = new ListNode(carry);
            temp->next = curr;
            temp = curr;
        }
        
        return head->next;
    }
};
