#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
 int y; 
 cin>>y; 
 for(int j=1;j<=y;j++) 
 { 
  int x; 
  cin>>x; 
  deque <int> a; 
  for(int i=1;i<=x;i++) 
  { 
   a.push_back(0); 
  } 
  int c=0,d=0; 
  while(c<x) 
  { 
   if(a.front()!=0) 
   { 
    a.push_back(a.front()); 
    a.pop_front(); 
    continue; 
   } 
   d++; 
   if(d==c+2) 
   { 
    c++; 
    a.push_back(c); 
    d=0; 
   } 
   else 
   { 
    a.push_back(0); 
   } 
   a.pop_front(); 
  } 
  while(1) 
  { 
   if(a.front()==1) 
   { 
    a.push_front(a.back()); 
    a.pop_back(); 
    break; 
   } 
   a.push_back(a.front()); 
   a.pop_front(); 
  } 
  while(!a.empty()) 
  { 
   cout<<a.front()<<" "; 
   a.pop_front(); 
  } 
  cout<<"\n"; 
 } 
 return 0; 
}