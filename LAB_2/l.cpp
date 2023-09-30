# include <iostream> 
# include <algorithm> 
# include <cassert> 
 
using namespace std; 
 
struct Node { 
  int val; 
  Node *next; 
 
  Node() { 
      val = 0; 
      next = NULL; 
  } 
 
}; 
 
 
 
int findMaxSum(int n, Node *head) { 
  // Implement this function 
  bool is_positive = false; 
 int max_so_far = -999999; 
  int max_ending_here = 0; 
  Node * cur = head; 
  while(cur){ 
    max_ending_here += cur->val; 
    if(cur->val > 0){ 
      is_positive = true; 
    } 
    if(max_so_far < max_ending_here){ 
      max_so_far = max_ending_here; 
    } 
    if(max_ending_here <0){ 
      max_ending_here = 0; 
    } 
    cur = cur->next; 
  } 
  // if(!is_positive){ 
  //   Node * newCur = head; 
  //   int max; 
  //   while(newCur->next){ 
  //     if(newCur >= newCur->next){ 
  //       max = newCur->val; 
  //     } 
  //     newCur = newCur->next; 
  //   } 
  //   return max; 
  // } 
  return max_so_far; 
 
} 
 
int main() { 
  int n; 
  cin >> n; 
 
  Node *head, *tail; 
  for (int i = 1; i <= n; ++i) { 
    int x; 
    cin >> x; 
    Node *cur = new Node(); 
    cur -> val = x; 
 
    if (i == 1) { 
      head = tail = cur; 
    } else { 
      tail -> next = cur; 
      tail = cur; 
    } 
  } 
 
  cout << findMaxSum(n, head) << "\n"; 
  return 0; 
}
