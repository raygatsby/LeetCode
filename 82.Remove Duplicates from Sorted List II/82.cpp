//
// Created by 许雷 on 2018/11/26.
//
//82. 删除排序链表中的重复元素 II
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode *new_head = new ListNode(head->val-1);
        new_head->next = head;

        ListNode *prepre = new_head;  // prepre表示已经从 head到prepre这个链表经过了筛选 这之间的结点全部满足条件
        ListNode *pre = new_head;  // pre表示正在验证的结点
        ListNode *p = head;  // p 一直往前验证pre

        while (p){

            if(p->val != pre->val){

                if(pre->next != p){
                    // 此时 pre是不符合要求的
                    // 将其中结点全部删除
                    prepre->next = p;
                    pre = p;
                    p = p->next;
                }else{
                    // 若 p->val!=pre->val 并且 pre->next==p 则表示pre经过了验证 pre是符合要求的
                    prepre = pre;
                    pre = pre->next;
                    p = p->next;
                }
            }else{
                // 若 p->val等于pre->val 则p继续往右找 看能找出几个pre->val出来
                p = p->next;
            }
        }

        // 循环退出时 有可能p任然在找pre的相同的结点 此时pre->next!=p所以把后面结点全部删除
        if(pre->next!=p){
            prepre->next = nullptr;
        }

        return new_head->next;
    }
};