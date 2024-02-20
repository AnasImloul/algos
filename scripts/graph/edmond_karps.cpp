#include "bits/stdc++.h"
using namespace std;

class Graph {
    vector<vector<pair<int, int>>> graph;
    int n;

public:
    Graph(int n) : n(n), graph(n) {}
    void add_edge(int a, int b, int flow) {
        graph[a].emplace_back(b, flow);
    }
    bool bfs(int source, int sink, vector<int>& parent) {
        vector<bool> visited(n, false);
        visited[source] = true;
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (const auto& [neighbor, capacity] : graph[current]) {
                if (!visited[neighbor] && capacity > 0) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    if (neighbor == sink) return true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

    int edmonds_karp(int source, int sink) {
        vector<int> parent(n, -1);
        int res = 0;

        while (bfs(source, sink, parent)) {
            int current = sink;
            int flow = INT_MAX;
            while (current != source) {
                int p = parent[current];
                for (const auto& [neighbor, capacity] : graph[p]) {
                    if (neighbor == current) {
                        flow = min(flow, capacity);
                        break;
                    }
                }
                current = p;
            }

            current = sink;
            while (current != source) {
                int p = parent[current];
                for (auto& [neighbor, capacity] : graph[p]) {
                    if (neighbor == current) {
                        capacity -= flow;
                        break;
                    }
                }
                for (auto& [neighbor, capacity] : graph[current]) {
                    if (neighbor == p) {
                        capacity += flow;
                        break;
                    }
                }
                current = p;
            }
            res += flow;
        }
        return res;
    }
};