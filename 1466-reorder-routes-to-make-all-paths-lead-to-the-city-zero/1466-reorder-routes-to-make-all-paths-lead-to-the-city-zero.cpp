class Solution {
public:
    int count = 0;
    
    void dfs(int node, vector<vector<pair<int, int>>>& adjList, int prev) {
        for(pair<int, int> e : adjList[node]) {
            if(e.first == prev) continue;
            if(e.second == 1) count++;
            dfs(e.first, adjList, node);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> vis(n+1, 0);
        
        vector<vector<pair<int, int>>> adjList(n);
        for(vector<int> c : connections) {
            adjList[c[0]].push_back({c[1], 1});
            adjList[c[1]].push_back({c[0], -1});
        }
        
        dfs(0, adjList, -1);
        
        return count;
    }
};