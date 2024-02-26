#include "bits/stdc++.h"
#include "../range_queries/segment_tree.cpp"
using namespace std;

class LCASegmentOp : public SegmentOp {
    int operator()(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return arr[a] < arr[b] ? a : b;
    }
    int operator()() { return -1; }
    int operator()(int i) { return i; }

public:
    explicit LCASegmentOp(vector<int>& arr) : SegmentOp(arr) {}
};

void euler_tour(int u, int p, vector<vector<int>>& graph, vector<int>& euler, vector<int>& depth, int d) {
    euler.push_back(u);
    depth.push_back(d);
    for (int& v : graph[u]) {
        if (v != p) {
            euler_tour(v, u, graph, euler, depth, d + 1);
            euler.push_back(u);
            depth.push_back(d);
        }
    }
}

int lca(int u, int v, vector<int>& euler, vector<int>& depth, vector<int>& index, SegmentTree& st) {
    int l = index[u];
    int r = index[v];
    if (l > r) swap(l, r);
    cout << st.query(l, r) << endl;
    return euler[st.query(l, r)];
}