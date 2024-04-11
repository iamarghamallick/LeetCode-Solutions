class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[node] = true;
        
        for(int key : rooms[node])
            if(!visited[key])
                dfs(key, rooms, visited);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        // stack<int> st;
        
        // st.push(0);
        // visited[0] = true;
        
        // while(!st.empty()) {
        //     int curr = st.top();
        //     st.pop();
        //     for(int key : rooms[curr]) {
        //         if(!visited[key]) {
        //             st.push(key);
        //             visited[key] = true;
        //         }
        //     }
        // }
        
        dfs(0, rooms, visited);
        
        for(int visit : visited)
            if(!visit)
                return false;
        
        return true;
    }
};