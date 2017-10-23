//Sort a linked list using insertion sort. 
// 1. 添加个伪链表头，简化设计
// 2. 利用递归
class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
        if (!head || !head->next) return head;
        
        ListNode dummy(0), *p;
        dummy.next = insertionSortList(head->next);
        p = &dummy;

        while (p && p->next && head->val > p->next->val)
        {
            p = p->next;
        }
        head->next = p->next;
        p->next = head;

        return dummy.next;
    }
}；