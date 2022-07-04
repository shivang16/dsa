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
    bool isPalindrome(ListNode* head) {
        if(!head ||!head->next) return true;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast){
            if(!fast->next) break;
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << slow->val << endl;
        ListNode* prev = slow;
        ListNode* now = prev->next;
        ListNode* nxt = now->next;
        ListNode* L = prev;
        prev = NULL;
        // cout <<  now->val << " " << nxt->val << endl; 
        while(now->next){
            now->next = prev;
            prev = now;
            now = nxt;
            nxt = nxt->next;
        }
        now->next = prev;
        // cout <<  now->val  << " " << L->val << endl; 
        
        L->next = now;
        L=head;
        ListNode* R=now;
        while(R!=NULL){
            // cout << R->val << " " << L->val << endl;
            if(L->val!=R->val)
                return false;
            L = L->next;
            R = R->next;
        }
        return true;
    }
};