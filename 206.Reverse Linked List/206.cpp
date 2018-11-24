//
// Created by eden on 18-11-24.
//

//206.反转链表
// 迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *p = head;
        ListNode *new_head = nullptr;
        while (p){
            // 遍历原链表 把每个结点通过头插法插入到newhead上 即可实现链表反转
            ListNode *p_next = p->next;
            p->next = new_head;
            new_head = p;
            p = p_next;
        }
        return new_head;
    }
};

// 递归法 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode *new_head = reverseList(head->next); // 先把后面的链表反转
        head->next->next = head;  // 反转后的后面链表指向前一个链表
        head->next = nullptr;  // 前一个链表指向空
        return new_head;
    }
};