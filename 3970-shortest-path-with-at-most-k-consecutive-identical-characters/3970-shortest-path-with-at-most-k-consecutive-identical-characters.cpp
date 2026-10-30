
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, cnt] = pq.top();
            pq.pop();

            if (cost != dist[node][cnt])
                continue;

            if (node == n - 1)
                return (int)cost;

            for (auto [next, weight] : adj[node]) {
                int newCnt;

                if (labels[node] == labels[next]) {
                    newCnt = cnt + 1;
                } 
                else {
                    newCnt = 1;
                }

                if (newCnt > k)
                    continue;

                long long newCost = cost + weight;

                if (newCost < dist[next][newCnt]) {
                    dist[next][newCnt] = newCost;
                    pq.push({newCost, next, newCnt});
                }
            }
        }

        return -1;
    }
};
