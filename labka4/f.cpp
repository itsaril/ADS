#include <iostream>
using namespace std;

int n, p, sum;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode *insert(TreeNode *tree, int val) {
  if(!tree) {
    tree = new TreeNode(val);
    return tree;
  }
  if(val <= tree->val) tree->left = insert(tree->left, val);
  else tree->right = insert(tree->right, val);
  return tree;
}

void check(TreeNode *tree) {
  if(!tree) return;
  if(tree->right && tree->left) ++sum;
  check(tree->left);
  check(tree->right);
}

TreeNode *root;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p;
  root = insert(root, p);
  for(int _ = 1; _ < n; _++) {
    cin >> p;
    insert(root, p);
  }
  check(root);
  cout << sum;
  return 0;
}