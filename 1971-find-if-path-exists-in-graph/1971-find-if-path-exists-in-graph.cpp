class Solution {
public:
    bool solve(int src, int dest, unordered_map<int, vector<int>>& v, vector<bool>& visited) {
        if(src == dest)
            return true;
        
        visited[src] = true;
        
        for (int neighbor : v[src])
            if(!visited[neighbor])
                if(solve(neighbor, dest, v, visited))
                    return true;
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        unordered_map<int, vector<int>> v;
        
        for(const auto& edge : edges) {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        return solve(src, dest, v, visited);
    }
};