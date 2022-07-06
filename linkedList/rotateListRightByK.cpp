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
    int getSize(ListNode* head){
        ListNode* temp = head;
        int size = 0;
        while(temp){
            temp = temp->next;
            size++;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int size = getSize(head);
        k = k%size;
        if(k==0) return head;
        int l = size-k;
        ListNode* temp = head;
        ListNode* prev;
        while(l>0){
            l--;
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        ListNode* temp1 = temp;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
        head = temp1;
        return head;
    }
};