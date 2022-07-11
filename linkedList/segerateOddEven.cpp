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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* x;
        bool flag = true;
        ListNode* temp = head;
        ListNode* oHead = odd;
        ListNode* eHead = even;
        while(temp){
            if(flag){
                odd->next = temp;
                x = odd;
                odd = odd->next;    
            }else{
                even->next = temp;
                even = even->next;    
            }
            flag=!flag;
            temp = temp->next;
        }
        even->next = NULL;
        odd->next = eHead->next;
        delete(eHead);
        ListNode* ans = oHead->next;
        delete(oHead);
        return ans;
    }
};