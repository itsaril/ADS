#include <bits/stdc++.h> 
   
using namespace std; 
 
struct Node{ 
 Node * prev; 
 Node * next; 
 string val; 
 Node(string _val){ 
  prev = NULL; 
  next = NULL; 
  val = _val; 
 }  
}; 
 
Node * head = NULL; 
Node * tail = NULL; 
int cnt; 
void add_back(string s){ 
    Node * val = new Node(s); 
 cnt++; 
    if(!head){ 
        head = val; 
        tail = val; 
         
    } 
 else{ 
  tail ->next = val; 
  val->prev = tail; 
  tail = val; 
 
 } 
    
     
} 
void add_front(string s){ 
 
    Node * val = new Node(s); 
 cnt++; 
    if(!head){ 
        head = val; 
        tail = val; 
 
    } 
 else{ 
  val->next = head;  
  head->prev = val; 
  // head->prev = val; 
  head = val; 
 
 } 
 
    // val->prev = nullptr; 
} 
bool empty(){ 
    return !head; 
} 
void erase_front(){ 
    if(head == tail){ 
  head = nullptr; 
  tail = nullptr; 
 } 
 else{ 
  head = head->next; 
  head->prev = nullptr; 
 } 
     
} 
void erase_back(){ 
 if(head == tail){ 
  head = nullptr; 
  tail = nullptr; 
 } 
 else{ 
  tail = tail->prev; 
  tail->next = nullptr; 
 } 
     
     
} 
string front(){ 
    return head->val; 
} 
string back(){ 
    return tail->val; 
} 
void clear(){ 
 while(head){ 
  head = head->next; 
 } 
} 
 
   
int main() 
{ 
 string s; 
   
    while(cin >> s){ 
     if(s == "add_front"){ 
      string t; 
      cin >> t; 
      add_front(t); 
      cout << "ok" << endl; 
     } 
     if(s == "add_back"){ 
      string t; 
      cin >> t; 
      add_back(t); 
      cout << "ok" << endl; 
     } 
     if(s == "erase_front"){ 
      if(empty()){ 
       cout << "error" << endl; 
      } 
      else 
      { 
       cout << front() << endl; 
       erase_front(); 
      } 
     } 
     if(s == "erase_back"){ 
      if(empty()){ 
       cout << "error" << endl; 
      } 
      else{ 
       cout << back() << endl; 
       erase_back(); 
      } 
     } 
     if(s == "front"){ 
      if(empty()){ 
       cout << "error" << endl; 
      } 
      else{ 
       cout << front() << endl; 
      } 
     } 
     if(s == "back"){ 
      if(empty()){ 
       cout << "error" << endl; 
      } 
      else{ 
       cout << back() << endl; 
      } 
     } 
     if(s == "clear"){ 
      clear(); 
      cout << "ok" << endl; 
     } 
     if(s == "exit"){ 
      cout << "goodbye" << endl; 
      break; 
     } 
     
    } 
    return 0; 
}
