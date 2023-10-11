#include <iostream>
using namespace std;

bool z;
bool was[1001];
int n, x, y, max_w;
int sum[1001];

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode *root, *node;

void search(TreeNode *tree, int x, int level = 1) {
  if(!tree || was[tree->val]) return;
  was[tree->val] = 1;
  if(tree->val == x) {
    node = tree;
    sum[level + 1] += 1; 
    return;
  }
  search(tree->left, x, level + 1);
  search(tree->right, x, level + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  root = new TreeNode(1);
  cin >> n;
  for(int _ = 0; _ < n - 1; _++) {
    cin >> x >> y >> z;
    for(int i = 1; i <= n; i++) was[i] = 0;
    search(root, x);
    if(z) node->right = new TreeNode(y);
    else node->left = new TreeNode(y);
  }
  for(int i = 1; i <= 1000; i++) max_w = max(max_w, sum[i]);
  cout << max_w;
  return 0;
}