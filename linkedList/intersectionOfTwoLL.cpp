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
    int getSize(ListNode* head){
        int s = 0;
        ListNode* temp = head;
        while(temp){
            s++;
            temp = temp->next;
        }
        return s;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1 = getSize(headA);
        int s2 = getSize(headB);
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if(s2>s1) swap(temp1,temp2);
        int d = abs(s1-s2);
        for(int i=0;i<d;i++){
            temp1 = temp1->next;
        }
        while(temp1){
            if(temp1==temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};