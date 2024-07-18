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
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> map;
        vector<TreeNode*> leaves;
        
        DFS(root, map, leaves, {});
        
        int count = 0;
        
        for(int i=0; i<leaves.size(); i++) {
            for(int j=i+1; j<leaves.size(); j++) {
                for(int k = 0; k < min(map[leaves[i]].size(), map[leaves[j]].size()); k++) {
                    if(map[leaves[i]][k] != map[leaves[j]][k]) {
                        if((map[leaves[i]].size() - k + map[leaves[j]].size() - k) <= distance)
                            count++;
                        break;
                    }
                }
            }
        }
        
        return count;
    }
    
private:
    void DFS(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &map, vector<TreeNode*> &leaves, vector<TreeNode*> path) {
        if(!root)
            return;
        
        vector<TreeNode*> temp(path);
        temp.push_back(root);
        
        if(!root->left && !root->right) {
            leaves.push_back(root);
            map[root] = temp;
            return;
        }
        
        DFS(root->left, map, leaves, temp);
        DFS(root->right, map, leaves, temp);
    }
};