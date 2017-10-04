#include <iostream>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = head, *r = head, *p = head;
        while (n-- > 0)
            r = r->next;
        if (r == nullptr)
            return l->next;
        while (r){
            r = r->next;
            p = l;
            l = l->next;
        }
        p->next = l->next;
        return head;
    }
};