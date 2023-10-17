class Solution {
public:
    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> children;
        children.insert(leftChild.begin(), leftChild.end());
        children.insert(rightChild.begin(), rightChild.end());
        for(int i=0; i<n; i++) {
            if(children.find(i) == children.end())
                return i;
        }
        return -1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if(root == -1)
            return false;
        unordered_set<int> seen;
        stack<int> st;
        seen.insert(root);
        st.push(root);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            int children[] = {leftChild[node], rightChild[node]};
            for(int child : children) {
                if(child != -1) {
                    if(seen.find(child) != seen.end()) {
                        return false;
                    } 
                    st.push(child);
                    seen.insert(child);
                }
            }
        }
        return n == seen.size();
    }
};