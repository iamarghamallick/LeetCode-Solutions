/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> dirs = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        int i = 0, j = 0, currDir = 0;
        while(head) {
            ans[i][j] = head->val;
            
            int newI = i + dirs[currDir][0];
            int newJ = j + dirs[currDir][1];
            
            if(newI < 0 || newJ < 0 || newI >= m || newJ >= n || ans[newI][newJ] != -1)
                currDir = (currDir + 1) % 4;
            
            i += dirs[currDir][0];
            j += dirs[currDir][1];
            
            head = head->next;
        }
        
        return ans;
    }
};