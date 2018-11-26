//
// Created by 许雷 on 2018/11/26.
//

//16.18
// 92.反转链表II
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *start = new_head;
        ListNode *p = new_head;
        ListNode *pre;

        for(int i=0;i<=n;i++){
            if(i<m){
                // 这个判断语句让 p走到第一个需要反转的结点
                start = p;
                p = p->next;
                pre = start->next;  // pre指向反转后的最后一个结点 即现在的p结点
            } else{
                ListNode *tmp = start->next;
                ListNode *p_next = p->next;
                p->next = tmp;
                start->next = p;
                p = p_next;
                pre->next = p; // pre->next必须改变 才能把后面的串起来
            }
        }
        return new_head->next;
    }
};
