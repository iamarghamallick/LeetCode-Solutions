/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        
        Node* cur = root;
        Node* nxt = root->left;
        
        while(cur && nxt) {
            cur->left->next = cur->right; // linking each left node with right node from root [1: 2 -> 3]
            
            if(cur->next)
                cur->right->next = cur->next->left; // when at 2, linking 5 with 6 [2: 5 -> 6]
            
            cur = cur->next;
            if(!cur) {
                cur = nxt;
                nxt = cur->left;
            }
        }
        
        return root;
    }
};