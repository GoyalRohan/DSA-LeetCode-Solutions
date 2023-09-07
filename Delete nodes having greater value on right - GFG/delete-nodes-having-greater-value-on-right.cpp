//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node *reverse(Node *head)
    {
        Node *p = NULL , *q = head ; 
        while(q)
        {
            Node *nex = q->next ; 
            q->next = p ; 
            p = q ; 
            q = nex ; 
        }
        return p ; 
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next)
            return head ;
            
        head = reverse(head) ; 
        int last = INT_MIN ; 
        Node *cur = head , *prev = NULL; 
        
        while(cur)
        {
            if(cur->data >= last)
            {
                last = cur->data ; 
                prev = cur ; 
                cur = cur->next ; 
            }
            else
            {
                prev->next = cur->next ; 
                cur = cur->next ; 
            }
        }
        
        head = reverse(head); 
        
        return head ; 
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends