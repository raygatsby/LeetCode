//
// Created by 许雷 on 2018/11/5.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 142.找出链表环的位置
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(!head)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;


        while (fast){
            if(fast->next)
                fast = fast->next->next;
            else
                return NULL;
            slow = slow->next;
            if(fast==slow){
                // 有环时
                slow = head;
                while (fast!=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};