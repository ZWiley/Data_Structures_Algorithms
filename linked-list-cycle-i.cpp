// Given a linked list, determine if it has a cycle in it.
// Follow up:
// Can you solve it without using extra space? 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)    
            return false;
        
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;   
            }
        } 
        return false;
    }
};