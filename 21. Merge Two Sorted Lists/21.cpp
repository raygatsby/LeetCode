//
// Created by eden on 18-11-22.
//

// 链表结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//21. 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *head = new ListNode(-1);  // 假头部
        ListNode *cur = head;

        // 只有有一个链表走到尾部即可跳出循环
        while (l1!=NULL && l2!=NULL){

            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = l1==NULL?l2:l1;
        return head->next;
    }
};
