#include "bits/stdc++.h"
using namespace std;


void dfs1(int i, int p, vector<vector<int>>& graph, vector<int>& values, vector<int>& order, vector<int>& sum, int current) {
    order.push_back(i);
    sum.push_back(current);

    for (int& j : graph[i]) {
        if (j == p) continue;
        dfs1(j, i, graph, values, order, sum, current + values[j]);
    }
}

void dfs2(int i, int p, vector<vector<int>>& graph, vector<int>& size) {
    size[i] = 1;
    for (int& j : graph[i]) {
        if (j == p) continue;
        dfs2(j, i, graph, size);
        size[i] += size[j];
    }
}