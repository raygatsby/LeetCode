//
// Created by eden on 18-11-23.
//

// 链表结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//148.排序链表
// 快排
// 因为快排平均时间复杂度为nlogn 而归并的时间复杂度都是nlogn
// 所以对本题来说归并排序要比快排快
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(!head || !head->next)
            return head;
        quick_sort(head, nullptr);
        return head;
    }

    void quick_sort(ListNode *l,ListNode *r){

        // 如果采取前闭后开的形式 则知道pos后还要遍历一遍找到pos的前一个结点才能接着排序
        // 所以这里采取前闭后开的形式 编码上比较简单
        // 这点与数组不同
        if(l!=r && l->next!=r){
            ListNode *pos = qiege(l,r);
            quick_sort(l,pos);
            quick_sort(pos->next,r);
        }
    }

    ListNode *qiege(ListNode *l,ListNode *r){

        int key = l->val;

        ListNode *pos = l;  // pos表示从开头到pos这一区间内都是比 key值小的结点

        for(ListNode *i = l->next;i!=r;i = i->next){

            if(i->val < key){
                // 如果遇到比key小的就把pos右移在把pos与这个符合条件的结点值进行交换
                pos = pos->next;

                int tmp = pos->val;
                pos->val = i->val;
                i->val = tmp;
            }
        }

        // 扫描完成后 把pos跟选定值 即l进行交换 这样就保证了在 pos左边的都是比pos现在这个结点的值要小
        // pos就成了分割点
        int tmp = pos->val;
        pos->val = l->val;
        l->val = tmp;

        return pos;
    }
};

//148.排序链表
// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode *pre,*slow,*fast;
        pre = slow = fast = head;
        while (fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;   // 将这个链表分成两个 分割点为 pre
        return merge(sortList(head),sortList(slow));
    }


    //把两个有序链表进行归并 leetcode21题就是这个
    ListNode* merge(ListNode *l1,ListNode *l2){

        ListNode *head = new ListNode(-1);
        ListNode *cur = head;

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