/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int> &ans) {
        if(!root)   return;
        for(int i=0; i<root->children.size(); i++)
            solve(root->children[i], ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> ans;
        // solve(root, ans);
        
        if(!root)
            return ans;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()) {
            Node* curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            
            for(Node* child : curr->children)
                st.push(child);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};