class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode* ans = nullptr;
        // for(auto list:lists){
        //     ans= mergeTwoLists(ans,list); // 顺序合并两个链表
        // }
        // return ans;

        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& list, int left, int right) {
        if (left == right) return list[left];
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        return mergeTwoLists(merge(list, left, mid), merge(list, mid + 1, right)); // 分冶递归合并链表
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // 合并两个链表的函数
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* pre = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                pre->next = list1;
                list1 = list1->next;
                pre = pre->next;
            }
            else {
                pre->next = list2;
                list2 = list2->next;
                pre = pre->next;
            }
        }
        if (list1 == nullptr && list2 != nullptr) pre->next = list2;
        if (list2 == nullptr && list1 != nullptr) pre->next = list1;
        return head->next;
    }
};