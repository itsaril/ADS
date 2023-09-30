#include <bits/stdc++.h> 
using namespace std; 
struct node{ 
    int val; 
    node *next; 
 
 
    node(){ 
        this -> val  = 0; 
        this -> next =NULL; 
} 
    node(int val){ 
        this -> val = val; 
        this -> next = NULL; 
 
} 
} 
; 
struct LinkedList{ 
    node *head; 
    node *tail; 
    LinkedList() 
    { 
        this -> head = NULL;  
        this -> tail = NULL; 
    } 
     
 
 
    void push_back(int val){ 
        node *temp = new node(val); 
 
        if(this -> head ==  NULL){ 
            this -> head = temp; 
            this -> tail = temp; 
        } 
        else{ 
            this -> tail -> next = temp; 
            this -> tail = temp; 
        } 
         
} 
 
; 
    int get_Nearest(int k) 
    { 
        node *cur = this -> head; 
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
} 
; 
int main()  { 
    LinkedList *ll = new LinkedList(); 
    int n; 
    cin >> n; 
 
for(int i = 0 ; i <n; i++){ 
    int b; 
    cin >> b; 
    ll -> push_back(b); 
} 
    int k; 
    cin >> k; 
    cout << ll->get_Nearest(k); 
 
}
