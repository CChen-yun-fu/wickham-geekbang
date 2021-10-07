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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* List1 = l1;
        ListNode* list2 = l2;
        ListNode* phead = new ListNode(-1);
        ListNode* pre = phead;
        while (List1 && list2) {
            if (List1->val < list2->val) {
                pre->next = List1;
                List1 = List1->next;
                pre = pre->next;
            }
            else {
                pre->next = list2;
                list2 = list2->next;
                pre = pre->next;
            }
        }
        if (List1 == nullptr) { pre->next = list2; }
        if (list2 == nullptr) { pre->next = List1; }
        return phead->next;

    }
};