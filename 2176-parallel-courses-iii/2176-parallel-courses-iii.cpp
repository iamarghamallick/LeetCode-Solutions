class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree = vector(n, 0);

        for(vector<int>& edge: relations) {
            int x = edge[0]-1;
            int y = edge[1]-1;
            graph[x].push_back(y);
            indegree[y]++;
        }

        queue<int> q;
        vector<int> maxTime = vector(n, 0);

        for(int node=0; node<n; node++) {
            if(indegree[node] == 0) {
                q.push(node);
                maxTime[node] = time[node];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neighbor: graph[node]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        int ans = 0;
        for(int node=0; node<n; node++) {
            ans = max(ans, maxTime[node]);
        }

        return ans;
    }
};