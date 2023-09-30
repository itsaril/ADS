#include <iostream>
#include <vector>
using namespace std;

string s;
vector<char> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for(char i : s) {
    if(v.size()) {
      if(i == v[v.size() - 1]) v.pop_back();
      else v.push_back(i);
    }else v.push_back(i);
  }
  if(v.size()) cout << "NO";
  else cout << "YES";
  return 0;
}