#include <iostream> 
#include <stack> 
using namespace std; 
// Node class for the expression tree 
class Node { 
public: 
char data; 
Node* left; 
Node* right; 
Node(char val) : data(val), left(nullptr), right(nullptr) {} 
};
// Function to create an expression tree from prefix notation 
Node* createExpressionTree(string prefix) { 
stack<Node*> s; 
int n = prefix.size(); 
for (int i = n - 1; i >= 0; i--) { 
char ch = prefix[i]; 
if (isdigit(ch) || isalpha(ch)) { 
Node* node = new Node(ch); 
s.push(node); 
}
else {
Node* node = new Node(ch); 
node->left = s.top(); s.pop(); 
node->right = s.top(); s.pop(); 
s.push(node); 
} 
}
return s.top(); 
}
// Function to traverse the expression tree in post-order 
void postorderTraversal(Node* root) { 
if (root) { 
postorderTraversal(root->left); 
postorderTraversal(root->right); 
cout << root->data << " "; 
delete root; 
} 
}
int main() { 
string prefix = "+--a*bc/def"; 
Node* root = createExpressionTree(prefix); 
cout << "Postorder traversal: "; 
postorderTraversal(root); 
cout << endl; 
return 0; 
}







