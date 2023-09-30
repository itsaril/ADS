#include <bits/stdc++.h> 
using namespace std; 
struct Node{ 
    int val; 
    Node* next; 
    Node(){ 
        this->val = 0; 
        this->next = NULL; 
    } 
    Node(int val){ 
        this->val = val; 
        this->next = NULL; 
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
    void push_back(int val){ 
        Node *tmp = new Node(val); 
        if(!this->head){ 
            this->head = tmp; 
            this->tail = tmp; 
        } 
        else{ 
            this->tail->next = tmp; 
            this->tail = tmp; 
        } 
        // cnt++; 
    } 
    void pushPos(int val, int pos){ 
        Node * cur = head; 
        Node * newNode = new Node(val); 
 
        if(pos == 0){ 
            newNode->next = head; 
            head = newNode; 
            return; 
        } 
        while(cur){ 
            cnt++; 
             
            if(cnt == pos ){ 
                newNode->next = cur->next; 
                cur->next = newNode; 
            } 
             
            cur = cur->next; 
        } 
    } 
  
    void print(){ 
        Node * cur = head; 
        while(cur){ 
            cout<<cur->val<<" "; 
            cur= cur->next; 
        } 
    } 
}; 
int main() { 
    LinkedList *ll = new LinkedList(); 
    int n; 
    cin>>n; 
    for(int i = 0 ; i< n ; i++){ 
        int k; 
        cin>>k; 
        ll->push_back(k); 
    } 
    int val; 
    int pos; 
    cin>>val>>pos; 
    ll->pushPos(val, pos); 
    ll->print(); 
    return 0; 
}
