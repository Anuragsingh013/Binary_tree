#include <iostream>
#include <queue>
using namespace std;
class node {
public:
  int data;
  node *left;
  node *right;
  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
node *buildtree(node *root) {
  cout << "enter the data" << endl;
  int data;
  cin >> data;
  root = new node(data);
  if (data == -1) {
    return NULL;
  }
  cout << "enter the data for insertion in left of " << data << endl;
  root->left = buildtree(root->left);

  cout << "enter the data for insertion in right of " << data << endl;
  root->right = buildtree(root->right);
  return root;
}
void levelordertraversal(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      // purana level complete traverse ho chuka h
      cout << endl;

      if (!q.empty()) {
        // queue still hava some child nodes
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}
void inorder(node *root) {
  // base case
  // LNR
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
int main() {
  
  node *root = NULL;
  // create a tree
  root = buildtree(root);
  cout << "printing the level order traversal output" << endl;
  levelordertraversal(root);
  cout << "printing the inorder traversal output" << endl;
  inorder(root);
  return 0;
}