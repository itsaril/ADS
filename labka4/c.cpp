#include <iostream>
using namespace std;
int n, p, x;

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

TreeNode *search(TreeNode *tree, int val) {
  if(!tree || tree->val == val) return tree;
  if(tree->val < val) return search(tree->right, val);
  return search(tree->left, val);
}

void print(TreeNode *tree) {
  if(!tree) return;
  cout << tree->val << " ";
  print(tree->left);
  print(tree->right);
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
  cin >> x;
  root = search(root, x);
  print(root);
  return 0;
}