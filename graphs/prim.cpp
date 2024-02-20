#include "bits/stdc++.h"
using namespace std;

int prim(vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(graph.size(), INT_MAX);

    auto cmp = [&](const int& a, const int& b) {
        return dist[a] > dist[b];
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(0);
    dist[0] = 0;

    int cost = 0;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        cost += dist[u];
        dist[u] = -1;

        for (auto& [v, w] : graph[u]) {
            if (dist[v] != -1 && w < dist[v]) {
                dist[v] = w;
                pq.push(v);
            }
        }
    }
}