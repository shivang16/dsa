/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* now = head;
        ListNode* nxt = head->next;
        while(now->next){
            now->next = prev;
            prev = now;
            now = nxt;
            nxt = nxt->next;
        }
        now->next = prev;
        return now;
    }
};