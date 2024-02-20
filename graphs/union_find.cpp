#include "bits/stdc++.h"
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;

        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};