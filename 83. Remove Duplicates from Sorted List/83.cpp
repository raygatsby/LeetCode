//
// Created by 许雷 on 2018/11/26.
//


//83. 删除排序链表中的重复元素
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *pre = head;
        ListNode *p = head->next;

        while (p){

            if(p->val == pre->val){
                pre->next = p->next;
                p = p->next;
            }else{
                pre = p;
                p = p->next;
            }
        }
        return head;

    }
};