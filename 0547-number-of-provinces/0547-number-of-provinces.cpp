class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true;
        
        for(int key : adjList[node])
            if(!visited[key])
                dfs(key, adjList, visited);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // converting given adj matrix (isConnected) into adj list (adjList)
        vector<vector<int>> adjList(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        
        int count = 0;        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, adjList, visited);
            }
        }
        
        return count;
    }
};