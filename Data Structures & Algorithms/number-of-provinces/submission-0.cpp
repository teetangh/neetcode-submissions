class Solution {

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode])
                dfs(adjNode, adj, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size();
        int m = adjMatrix[0].size();
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(adjMatrix[i][j] == 1)
                    // push only once as adjMatrix will take care of the other
                    adj[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);

        int cc_count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                cc_count++;
            }
        }

        return cc_count;
    }
};