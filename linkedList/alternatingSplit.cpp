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
        int ans = 0;
        ListNode* temp = head;
        while(temp){
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector <ListNode*> ans;
        int l = getSize(head);
        // if(l==0||l==1||k==1) {ans.push_back(head); return ans;}
        int parts = l/k;
        int rem = l%k;
        ListNode* temp = head;
        for(int i=0;i<k;i++){
            int count =rem<=0?0:1;
            count+=parts;
            rem--;
            // cout << count <<" " << temp->val<< endl;
            if(count==0) ans.push_back(NULL);
            else{
                ListNode* prev;
                ans.push_back(temp);
                for(int j=0;j<count;j++){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
            }
        }
        return ans;
    }
};