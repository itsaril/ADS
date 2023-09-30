#include <iostream> 
 
using namespace std;  
 
class Node   
{   
    public:  
    string data;   
    Node* next;   
};   
   
void removeDuplicates(Node* head)   
{   
    Node * cur = head; 
    Node * next_next; 
    if(!cur) return; 
 
    while(cur->next){ 
        if( cur -> data == cur->next->data){ 
 
            next_next = cur->next->next; 
            free(cur->next); 
            cur->next = next_next; 
        } 
        else{ 
            cur = cur->next; 
        } 
    } 
     
}   
 
Node* reverse(Node* head){ 
    Node * next = nullptr; 
    Node * prev = nullptr; 
    Node * cur = head; 
    while(cur){ 
        next = cur->next; 
        cur->next = prev; 
        prev = cur; 
        cur = next; 
    } 
    // head = prev; 
    return prev; 
} 
 
 
int getCount(Node* head)   
{   
    int count = 0;  
    Node*cur = head; 
    while(cur){ 
        count++; 
        cur= cur->next; 
    } 
    return count;   
}   
 
void push(Node** head_ref, string new_data)   
{  
    Node* new_node = new Node();  
               
 
    new_node->data = new_data;   
                   
 
    new_node->next = (*head_ref);       
           
 
    (*head_ref) = new_node;   
}   
  
 
void printList(Node *node)   
{   
    while (node!=NULL)   
    {   
        cout<<node->data<<"\n";   
        node = node->next;   
    }   
}   
 
int main()   
{   
    int n; 
    string s; 
    cin>>n; 
    Node* head = NULL;   
    for(int i =0;i<n;i++){ 
        cin>>s; 
        push(&head,s); 
    } 
                                       
    removeDuplicates(head);   
    
    cout<<"All in all: "<<getCount(head); 
     
    cout<<"\nStudents:\n";       
    printList(head);               
   
    return 0;   
}
