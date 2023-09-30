#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char last;
int n, cnt, flag, need, k;
string s;
vector<char> v, vv;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  do {
    flag = -1;
    v.clear();
    vv.clear();
    for(char i : s) {
      if(vv.size()) {
        last = vv[vv.size() - 1];
        if((last == 'K' && i == 'S') || (last == 'S' && i == 'K')) vv.pop_back();
        else {
          v.push_back(i);
          vv.push_back(i);
        }
      }else {
        v.push_back(i);
        vv.push_back(i);
      }
    }
    if(vv.size()) flag = (vv[0] == 'K');
    if(flag == 1) {
      need = vv.size(), k = 0;
      for(int i = 0; i < v.size() - k; i++) {
        if(need == 0) break;
        if(v[i] == 'S') {
          v.erase(v.begin() + i--);
          ++k;
          --need;
        }
      }
    }else if(flag == 0) {
      need = vv.size(), k = 0;
      for(int i = 0; i < v.size() - k; i++) {
        if(need == 0) break;
        if(v[i] == 'K') {
          v.erase(v.begin() + i--);
          ++k;
          --need;
        }
      }
    }
    cnt = count(v.begin(), v.end(), 'K');
    s = "";
    for(char i : v) s += i;
  }while(cnt > 0 && cnt != v.size());
  if(cnt) cout << "KATSURAGI";
  else cout << "SAKAYANAGI";
  return 0;
}