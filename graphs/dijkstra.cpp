#include <bits/stdc++.h>
using namespace std;

int dijkstra(int i, int j, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[i] = 0;

    auto cmp = [&](const int& a, const int& b) {
        return dist[a] > dist[b];
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(i);

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(v);
            }
        }
    }

    return dist[j];
}
