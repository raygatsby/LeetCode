//
// Created by 许雷 on 2018/11/5.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//141.判断链表是否有环
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast){
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};
