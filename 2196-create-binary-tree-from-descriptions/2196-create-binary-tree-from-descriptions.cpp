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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, int> leftMap; // <root, left>
        unordered_map<int, int> rightMap; // <root, right>
        unordered_set<int> set;
        
        for(int i=0; i<desc.size(); i++) {
            
            int rootVal = desc[i][0];
            int childVal = desc[i][1];
            int isLeft = desc[i][2];
            
            if(isLeft)  leftMap[rootVal] = childVal;
            else        rightMap[rootVal] = childVal;
            
            set.insert(childVal);
        }
        
        // finding the root node value
        int start = 0;
        for(int i=0; i<desc.size(); i++)
            if(set.find(desc[i][0]) == set.end())
                start = desc[i][0];
        
        TreeNode *root = new TreeNode(start);
        
        constructTree(root, leftMap, rightMap);
        
        return root;
    }
    
private:
    void constructTree(TreeNode* &root, unordered_map<int, int> &leftMap, unordered_map<int, int> &rightMap) {
        int currVal = root->val;
        TreeNode* leftPtr = nullptr, *rightPtr = nullptr;
        if(leftMap[currVal])    leftPtr = new TreeNode(leftMap[currVal]);
        if(rightMap[currVal])    rightPtr = new TreeNode(rightMap[currVal]);
        root = new TreeNode(currVal, leftPtr, rightPtr);
        if(leftPtr)     constructTree(root->left, leftMap, rightMap);
        if(rightPtr)     constructTree(root->right, leftMap, rightMap);
    }
};