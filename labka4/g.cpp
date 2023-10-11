#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *left, *right;

  Node (int val) {
    this->val = val;
    left = right = nullptr;
  }
};

struct BST {
private:
  Node *root;

  Node* insert(Node *root, int val) {
    if (!root) {
      return new Node(val);
    }

    if (val > root->val) {
      root->right = insert(root->right, val); 
    }

    else if (val < root->val){
      root->left = insert(root->left, val);
    }

    return root;
  }

public:
  BST () {
    root = nullptr;
  }

  Node* getroot() {
    return root;
  }

  void add(int val) {
    Node* newnode = insert(root, val);

    if (!root) root = newnode;
  }

  int count(Node* root, int& cnt) {
    if (!root) return 0;

    int l = count(root->left, cnt);
    int r = count(root->right, cnt);

    cnt = max(l + r + 1, cnt);
    return max(l, r) + 1;
  }
};

int main() {
  BST bst;

  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bst.add(x);
  }
  
  int cnt = 0;
  bst.count(bst.getroot(), cnt);
  cout << cnt;

  return 0;
}