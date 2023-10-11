#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *left, *right;

  Node (int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
}; 

struct BST {
  Node *root;

private:
  Node* _insert(Node* cur, int val) {
    if (!cur) {
      return new Node(val);
    }
    
    if (val > cur->val) {
      cur->right = _insert(cur->right, val);
    } 
    
    else if (val < cur->val) {
      cur->left = _insert(cur->left, val);
    }

    return cur;
  }


  void _inorder(Node *node) {
    if (!node) return;
    _inorder(node->right);
    cout << node->val << " ";
    _inorder(node->left);
  }

public:
  BST () {
    root = nullptr;
  }

  Node* getroot() {
    return root;
  }

  void insert(int val) {
    root = _insert(root, val);
  }

  void inorder() {
    _inorder(root);
  }

  void rev(Node* node, int& sum) {
    if (!node) return;
    
    rev(node->right, sum);
    
    sum += node->val;
    node->val = sum;
    
    rev(node->left, sum);
  }
};

int main() {
  BST bst;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bst.insert(x);
  }

  int sum = 0;
  bst.rev(bst.getroot(), sum);
  bst.inorder();

  return 0;
}