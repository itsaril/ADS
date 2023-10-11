#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int a[32768];

void solve(int l, int r) {
  if(l > r) return;
  int mid = (l + r) / 2;
  cout << a[mid] << " ";
  solve(l, mid - 1);
  solve(mid + 1, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  n = pow(2, n) - 1;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  solve(1, n);
  return 0;
}