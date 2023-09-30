
#include <iostream> 
#include <stack> 
#include <vector> 
using namespace std; 
 
int solve(int x,deque <int> &dq){ 
  if(dq.size()==0){ 
    dq.push_back(x); 
    return -1; 
  } 
  deque <int> :: iterator it; 
  for(it = dq.end()-1;it!=dq.begin()-1;--it){ 
    if(x >= *it){ 
        dq.push_back(x); 
        return (*it); 
    } 
  } 
  dq.push_back(x); 
  return -1; 
}

 
int main(){ 
int n; 
cin>>n; 
deque <int> dq; 
deque <int> :: iterator it; 
  for(int i=0;i<n;++i){ 
    int x; 
    cin>>x; 
    cout<<solve(x,dq)<<" "; 
  } 
}

