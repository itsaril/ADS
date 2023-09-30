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
    } 
 
    void delsecond(){ 
        Node * cur = head; 
        while (cur && cur->next) 
        { 
            Node * tmp = cur->next; 
            cur->next = cur->next->next; 
            cur = cur->next; 
            free(tmp); 
        } 
         
         
         
    } 
 
    int getNearest(int k){ 
        Node *cur = this->head; 
        int min = 1e9, minpos = -1, cnt = 0; 
        while(cur){ 
            if((abs(k - cur->val)) < min){ 
                min = abs(k - cur->val); 
                minpos = cnt; 
            } 
            cur = cur->next; 
            cnt++; 
        } 
        return minpos; 
    } 
    void print(){ 
        Node * cur = this -> head; 
        while (cur) 
        { 
            cout<<cur->val<<" "; 
            cur = cur->next; 
        } 
 
        cout<<endl; 
    } 
}; 
int main() { 
    LinkedList *ll = new LinkedList(); 
    int n; 
    cin >> n; 
    while(n--){ 
        int k; 
        cin>>k; 
        ll->push_back(k); 
 
    } 
 
    ll->delsecond(); 
 
    ll->print(); 
    return 0; 
}
