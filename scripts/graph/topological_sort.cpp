#include "bits/stdc++.h"
using namespace std;

void topological_sort(int i, vector<vector<int>>& graph, vector<int>& state, vector<int>& order) {
    if (state[i] != 0) return;

    state[i] = 1;
    for (int& j : graph[i])
        topological_sort(j, graph, state, order);

    state[i] = 2;
    order.push_back(i);
}