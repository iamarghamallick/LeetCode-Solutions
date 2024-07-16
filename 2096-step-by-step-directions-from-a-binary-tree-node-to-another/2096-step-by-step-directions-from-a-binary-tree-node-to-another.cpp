/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart = "", pathToDest = "";
        traverse(root, startValue, pathToStart);
        traverse(root, destValue, pathToDest);
        removeLCP(pathToStart, pathToDest);
        replaceWithU(pathToStart);
        return pathToStart + pathToDest;
    }

private:
    bool traverse(TreeNode* root, int target, string &path) {
        if(!root)
            return false;
        
        if(root->val == target)
            return true;
        
        path.push_back('L');
        if(traverse(root->left, target, path))
            return true;
        path.pop_back();
        
        path.push_back('R');
        if(traverse(root->right, target, path))
            return true;
        path.pop_back();
        
        return false;
    }
    
    void removeLCP(string &s1, string &s2) {
        int i = 0;
        
        while(i < min(s1.size(), s2.size())) {
            if(s1[i] == s2[i])
                i++;
            else 
                break;
        }
        
        s1 = s1.substr(i);
        s2 = s2.substr(i);
    }
    
    void replaceWithU(string &s) {
        for(int i=0; i<s.size(); i++)
            s[i] = 'U';
    }
};