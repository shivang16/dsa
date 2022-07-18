//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

// } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    int getLength(Node* head){
        int ans = 0;
        Node* temp = head;
        while(temp){
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        if(!head) return;
        Node* temp = head;
        Node* prev = NULL;
        int L = getLength(head);
        // cout << L << endl;
        if(M>=L) return;
        // if(N>=L) return NULL;
        while(temp){
            for(int i=0;i<M;i++){
                if(!temp){
                    break;
                }else{
                    prev = temp;
                    temp = temp->next;
                }
            }
            
            for(int i=0;i<N;i++){
                if(!temp){
                    break;
                }else{
                    Node* nxt = temp->next;
                // cout << temp->data << " ";
                    delete(temp);
                    temp = nxt;    
                }
            }
            prev->next = temp;
        }
        return; 
        // cout << prev->data << " " << temp->data << endl;
        // while(temp && N>0){
        //     N--;
        //     Node* nxt = temp->next;
        //     cout << temp->data << " ";
        //     delete(temp);
        //     temp = nxt;
        // }
        // cout << endl<<temp->data <<endl; 
        // prev->next = temp;
        return;
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}

// } Driver Code Ends