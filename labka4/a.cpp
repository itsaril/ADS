#include <iostream>
using namespace std;

int n, m, p; //глобальные переменные
string s;

struct TreeNode {
  int val;
  TreeNode *left; //представляющая узел бинарного дерева поиска 
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


 /* Функция insert рекурсивно добавляет новый узел с заданным 
 значением в бинарное дерево поиска. Если узел пустой, 
 он создает новый узел с заданным значением. 
 Если значение меньше или равно текущему узлу, 
 функция рекурсивно вызывается для левого поддерева, 
 иначе для правого поддерева. */
TreeNode *insert(TreeNode *tree, int val) {
  if(!tree) {
    tree = new TreeNode(val);
    return tree;
  }
  if(val <= tree->val) tree->left = insert(tree->left, val);
  else tree->right = insert(tree->right, val);
  return tree;
}


/* Функция check проверяет, существует ли заданный путь (route) 
в бинарном дереве. Она принимает на вход строку, представляющую 
путь в дереве (где "L" означает движение влево, а "R" - движение вправо).
 Если путь существует в дереве, функция возвращает "YES", иначе "NO". */

string check(TreeNode *tree, string route) {
  TreeNode *node = tree;
  for(char i : route) {
    if(i == 'L') {
      node = node->left;
      if(!node) return "NO";
    }else {
      node = node->right;
      if(!node) return "NO";
    }
  }
  return "YES";
}


/*В функции main программа начинает выполнение. 
Она сначала вводит значения n, m и p, где n - количество 
узлов в бинарном дереве, m - количество путей для проверки,
 и p - значение корневого узла. Затем создается корень дерева 
 с помощью функции insert.*/

TreeNode *root;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  root = insert(root, p);
  for(int _ = 1; _ < n; _++) {
    cin >> p;
    insert(root, p);
  }
  for(int _ = 0; _ < m; _++) {
    cin >> s;
    cout << check(root, s) << "\n";
  }
  return 0;
}