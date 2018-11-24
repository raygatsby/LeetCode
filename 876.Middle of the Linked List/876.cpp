//
// Created by eden on 18-11-24.
//

//876.链表的中间结点
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};