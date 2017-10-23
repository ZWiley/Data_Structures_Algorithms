//Sort a linked list in O(n log n) time using constant space complexity. 
/*
  考点：
  1. 快慢指针；2. 归并排序。
  此题经典，需要消化吸收。
  复杂度分析:
             T(n)            拆分 n/2, 归并 n/2 ，一共是n/2 + n/2 = n
            /    \           以下依此类推：
          T(n/2) T(n/2)      一共是 n/2*2 = n
         /    \  /     \
        T(n/4) ...........   一共是 n/4*4 = n
 
       一共有logn层，故复杂度是 O(nlogn)
 */
class Solution{
public:
    ListNode *sortList(ListNode *head){
        if(!head || !head->next) return head;

        ListNode* p = head, *q = head->next;
        while (q && q->next)
        {
            p = p->next;
            q = q->next->next;
        }

        ListNode* left = sortList(p->next);
        p->next = NULL;
        ListNode* right = sortList(head);

        return merge(left, right);
    }

    ListNode* nerge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                p->next = left;
                left = left->next;
            }else
            {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left) p->next = left;
        if (right) p->next = right;
        return dummy.next;
    }
};
