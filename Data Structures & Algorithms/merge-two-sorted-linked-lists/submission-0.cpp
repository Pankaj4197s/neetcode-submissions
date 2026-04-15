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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        else if (!list2)
            return list1;
        else {
            ListNode* nHead;
            ListNode* t1 = list1;
            ListNode* t2 = list2;
            if (t1->val <= t2->val) {
                nHead = t1;
                t1 = t1->next;
            } else {
                nHead = t2;
                t2 = t2->next;
            }
            ListNode* temp = nHead;
            while(t1 && t2) {
                if (t1->val <= t2->val) {
                    temp->next = t1;
                    t1 = t1->next;
                    temp = temp->next;
                } else {
                    temp->next = t2;
                    t2 = t2->next;
                    temp = temp->next;
                }
            }
            while(t1) {
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
            }
            while(t2) {
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }
            return nHead;
        }
    }
};
