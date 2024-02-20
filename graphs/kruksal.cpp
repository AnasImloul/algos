#include "bits/stdc++.h"
using namespace std;

int find(int i, vector<int>& parent) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i], parent);
}

void unite(int i, int j, vector<int>& parent) {
    i = find(i, parent);
    j = find(j, parent);
    parent[i] = j;
}

vector<int> kruksal(vector<pair<int, pair<int, int>>>& edges, int n) {
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<int> order;
    sort(edges.begin(), edges.end());
    for (auto& [w, p] : edges) {
        auto [i, j] = p;
        if (find(i, parent) != find(j, parent)) {
            unite(i, j, parent);
            order.push_back(w);
        }
    }
    return (order.size() == n - 1) ? order : vector<int>();
}