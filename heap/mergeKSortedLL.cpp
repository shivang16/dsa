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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* last = NULL;
        int n = lists.size();
        
        // val,ptr
        
        priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> Q;
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
                Q.push({lists[i]->val,lists[i]});
        }
        
        while(!Q.empty()){
            int val = Q.top().first;
            ListNode* node = Q.top().second;
            ListNode* nnode = new ListNode(val);
            Q.pop();
            if(head==NULL){
                head = nnode;
            }else{
                last->next = nnode;
            }
            last = nnode;
            
            if(node->next!=NULL){
                Q.push({node->next->val,node->next});
            }
        }
        // if(head==NULL){
        //     cout << "bye";
        // }
        return head;
    }
};