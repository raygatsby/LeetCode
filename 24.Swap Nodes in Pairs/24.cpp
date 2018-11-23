//
// Created by eden on 18-11-23.
//

//24. 两两交换链表中的节点
//真实结点交换 而不是仅仅进行值的交换
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // 本题使用4个结点来完成交换两个结点
        // 用pre p1 p2 next来把 p1 p2 进行交换
        // 关系为pre->p1->p2->next
        //头结点特殊处理
        if(!head || !head->next)
            return head;

        // 下面交换头结点和他的下一个结点
        // 因为头结点没有前驱结点 所以特殊处理
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *next = p2->next;

        p2->next = p1;
        p1->next = next;
        head = p2;

        ListNode *pre = p1;
        p1 = pre->next;
        if(!p1)
            return head;
        p2 = p1->next;
        if(!p2)
            return head;
        next = p2->next;


        while (p1 && p2){

            p2->next = p1;
            p1->next = next;
            pre->next = p2;   // 上面3行完成结点交换

            pre = p1;
            p1 = pre->next;
            if(!p1)
                return head;
            p2 = p1->next;
            if(!p2)
                return head;
            next = p2->next;  // 上面几行是将 pre p1 p2 next 集体往后移

        }
    }
};