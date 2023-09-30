#include <iostream> 
#include <cmath> 
#include <vector> 
using namespace std; 
 
bool p[1000001]; 
int n, N = 1000000; 
vector<int> v, vv; 
 
int prime(int n) { 
  for(int i = 2; i <= sqrt(n); i++) { 
    if(n % i == 0) return false; 
  } 
  return true; 
} 
 
int main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  for(int i = 2; i <= N; i++) p[i] = true; 
  for(int i = 2; i * i <= N; i++) { 
    if(p[i]) { 
      for(int j = i * i; j <= N; j += i) p[j] = false; 
    } 
  } 
  for(int i = 1; i <= N; i++) { 
    if(p[i]) v.push_back(i); 
  } 
  for(int i = 1; i <= v.size(); i++) { 
    if(p[i]) vv.push_back(v[i - 1]); 
  } 
  cin >> n; 
  cout << vv[n - 1]; 
  return 0; 
}
