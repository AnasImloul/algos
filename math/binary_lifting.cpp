#include "bits/stdc++.h"
using namespace std;

int kth_parent(int node, int k, vector<vector<int>>& parent) {
    int i = 0;
    while (k > 0) {
        if (k & 1)
            node = parent[i][node];
        k >>= 1;
        i++;
    }
    return node;
}

vector<vector<int>> build(int n, vector<int>& successor) {
    vector<vector<int>> parent(20, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        parent[0][i] = successor[i];

    for (int i = 1; i < parent.size(); i++)
        for (int j = 0; j < n; j++) {
            if (parent[i - 1][j] == -1)
                parent[i][j] = -1;
            else
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    return parent;
}