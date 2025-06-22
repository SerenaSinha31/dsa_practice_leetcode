class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // understanding :
        // we have connected graph without cycle so it is a tree and we can use
        // bfs as it stated min height and we have to take one level at a time
        // and mark it as one height level

        // step 1 : create an adj list
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        if(n ==1){
            return {0};
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // now we have adj list, now we have to work with queue and apply bfs
        // breadth wise we have to put the leaf ele in queue and and we can
        // reconise leaf ele which have indegree of 1
        queue<int> q;
        // check for leaf node and add in queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        // bfs -> in this in while we are checking that we should remain with
        // last 1 0r 2 ele which is definately our ans as if we want to know the
        // min height we should start from centre not from leaf nodes so at last
        // we remain with either one or two index ans
        while (n > 2) {
            int size = q.size();

            // now delete the processed size from n
            n -= size;

            while (size--) {
                int u = q.front();
                q.pop();

                // now check adj list for u and decrease its indegree
                for (auto& v : adj[u]) {
                    indegree[v]--;
                    if (indegree[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        vector<int> res;
        // now after above while we remain with either one or two min height
        // heads
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
    /*
        // Brute force TLE
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            // making adjacency list first
            vector<vector<int>> adj(n);
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            // considering each node as a root and checking for height
            int minHeight = INT_MAX;
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                int level = 0;
                queue<int> que;
                vector<int> vis(n, 0);
                que.push(i);
                vis[i] = 1;
                while (!que.empty()) {
                    int size = que.size();
                    for (int j = 0; j < size; j++) {
                        int node = que.front();
                        que.pop();
                        for (auto& it : adj[node]) {
                            if (vis[it] == 0) {
                                que.push(it);
                                vis[it] = 1;
                            }
                        }
                    }
                    if (!que.empty()) {
                        level++;
                    }
                }
                if (level < minHeight) {
                    minHeight = level;
                    ans.clear();
                    ans.push_back(i);
                } else if (level == minHeight) {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    */
};