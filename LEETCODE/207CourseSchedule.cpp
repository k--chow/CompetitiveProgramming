class Solution {
public:
    bool ans = true;
    void dfs(int current, vector< vector<int> >& adj, vector<int> & visited)
    {
        visited[current] = -1;
        for(int i=0; i<adj[current].size(); i++)
        {
            int neighbor = adj[current][i];
            if (visited[neighbor] == -1) {
               ans = false;
               return;
            }
            if (visited[neighbor] == 0)
            {
                dfs(neighbor, adj, visited);
            }
        }
        visited[current] = 1;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > adj(numCourses);
        vector<int> visited(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        //loop through all nodes if unvisited
        for(int i=0; i<numCourses; i++)
        {
            if (visited[i] == 0) dfs(i, adj, visited);
        }
        return ans;
    }
};
