#include <bits/stdc++.h> 
using namespace std; 
struct Node{ 
    char val; 
    Node* next; 
    Node* prev; 
    bool repeated; 
    Node(){ 
        this->val; 
        this->next = NULL; 
        this->repeated = false; 
    } 
    Node(char val){ 
        this->val = val; 
        this->next = NULL; 
        this->repeated = false; 
 
    } 
}; 
int cnt = 0; 
struct LinkedList{ 
    Node* head; 
    Node* tail; 
    LinkedList(){ 
        this->head = NULL; 
        this->tail = NULL; 
    } 
    void push_back(char val){ 
        Node *tmp = new Node(val); 
 
        if(!head){ 
            head = tmp; 
            tail = tmp; 
        } 
 
        else{ 
            Node * cur = head; 
            while(cur){ 
                if(cur->val == val){ 
                    cur->repeated = true; 
                    return; 
                } 
                cur = cur->next; 
            } 
            tail->next = tmp; 
            tail = tmp; 
        } 
    } 
     
 
    
 
     
 
    void clear(){ 
        head = nullptr; 
    } 
}; 
 
   
int main() 
{ 
 int n; 
    cin>>n; 
     
    while(n--){ 
        int k; 
        cin>>k; 
        LinkedList *ll = new LinkedList(); 
 
        for(int i = 0 ; i< k ;i++){ 
            char val; 
            cin>>val; 
            ll->push_back(val); 
            bool founded = false; 
            Node * tmp = ll->head; 
            while(tmp){ 
                if(!tmp->repeated){ 
                    cout<<tmp->val<<" "; 
                    founded = true; 
                    break; 
                } 
 
                tmp=tmp->next; 
            } 
            if(!founded){ 
                cout<<"-1 "; 
            } 
             
        } 
            cout<<endl; 
         
         
 
    } 
    return 0; 
}
