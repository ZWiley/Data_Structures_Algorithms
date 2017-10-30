// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list. 
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
            RandomListNode *copy,*p;
            if (!head) return NULL;
            for(p=head;p;p=p->next){
                copy = new RandomListNode(p->label);
                copy->next = p->next; // insert new at old next
                p = p->next = copy;
            }
            for(p=head;p;p=copy->next){
                copy = p->next;          // copy random point
                copy->random = (p->random?p->random->next:NULL);
            }
            for(p=head,head=copy=p->next;p;){
                p = p->next = copy->next; // split list
                copy = copy->next = (p?p->next:NULL);
            }
            return head;
        }
};