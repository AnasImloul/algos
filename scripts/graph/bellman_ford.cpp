#include "bits/stdc++.h"
using namespace std;

int bellman_ford(int i, int j, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[i] = 0;

    for (int k = 0; k < graph.size() - 1; k++)
        for (int u = 0; u < graph.size(); u++)
            for (auto& [v, w] : graph[u])
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;

    return dist[j];
}