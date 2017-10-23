/**
Given a singly linked list L: L 0→L 1→…→L n-1→L n,
reorder it to: L 0→L n →L 1→L n-1→L 2→L n-2→…

You must do this in-place without altering the nodes' values.

For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}. 
*/
//快慢指针找到中间节点，将后面的链表反转（前插法），合并链表
class Solution{
public:
    void reorderList(ListNode* head){
        if (head ==NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        //快慢指针找中点
        ListNode* fast = head;
        ListNode* low  = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            low = low->next;   
        }
        //对low后面的部分逆序
        fast = low->next;
        low->next = NULL;
        while (fast != NULL)   
        {
            ListNode* temp = fast->next;
            fast->next = low->next;
            low->next = fast;
            fast = temp;   
        }

        //合并low前面和后面两部分
        ListNode* p = head;
        ListNode* q = low->next;
        while (p != NULL && q != NULL)
        {
            low->next = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = low->next;
        }
    }
};