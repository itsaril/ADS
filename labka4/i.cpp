#include <iostream>
using namespace std;

int q, p;
string command;

struct TreeNode {
  int val, mult;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), mult(1), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), mult(1), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), mult(1), left(left), right(right) {}
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

TreeNode *root, *node;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  for(int _ = 0; _ < q; _++) {
    cin >> command >> p;
    if(command == "insert") {
      if(!root) root = insert(root, p);
      else {
        node = search(root, p);
        if(!node) insert(root, p);
        else node->mult = node->mult + 1;
      }
    }else if(command == "cnt") {
      node = search(root, p);
      if(node) cout << node->mult;
      else cout << 0;
      cout << "\n";
    }else {
      node = search(root, p);
      node->mult = node->mult - 1;
    }
  }
  return 0;
}