//
// Created by eden on 18-11-22.
//

// 链表结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//19. 删除链表的倒数第N个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *fast = head;
        ListNode *slow = head;

        // 让快指针先走n步
        for(int i=0;i<n;++i){
            fast = fast->next;
        }
        if(!fast){
            return head->next;
        }
        //当快指针到达链表尾部时退出循环
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // 退出时slow的下一个结点就是要删除的结点

        slow->next = slow->next->next;
        return head;
    }
};