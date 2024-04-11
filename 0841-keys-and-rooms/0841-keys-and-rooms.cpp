class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        stack<int> st;
        
        st.push(0);
        visited[0] = true;
        
        while(!st.empty()) {
            int curr = st.top();
            st.pop();
            for(int key : rooms[curr]) {
                if(!visited[key]) {
                    st.push(key);
                    visited[key] = true;
                }
            }
        }
        
        for(int visit : visited)
            if(!visit)
                return false;
        
        return true;
    }
};