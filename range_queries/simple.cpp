#include "bits/stdc++.h"
using namespace std;

struct SegmentOp {
    vector<int>& arr;
    explicit SegmentOp(vector<int>& arr) : arr(arr) {}
    int operator()(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return arr[a] < arr[b] ? a : b;
    }
    int operator()() { return -1; }
    int operator()(int i) { return i; }
};

class SegmentTree {
public:
    SegmentOp op;
    vector<int> tree;
    vector<int>& arr;
    int n;

    SegmentTree(vector<int>& arr, SegmentOp op) : arr(arr), op(op), n((int)arr.size()) {
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    int build(int i, int l, int r) {
        if (l == r)
            return tree[i] = op(l);
        int m = (l + r) / 2;
        return tree[i] = op(build(2 * i + 1, l, m), build(2 * i + 2, m + 1, r));
    }

    int query(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return op();
        if (ql <= l && r <= qr) return tree[i];
        int m = (l + r) / 2;
        return op(query(2 * i + 1, l, m, ql, qr), query(2 * i + 2, m + 1, r, ql, qr));
    }

    void update(int i, int val) {
        update(0, 0, n - 1, i, val);
    }

    int update(int i, int l, int r, int qi, int val) {
        if (qi < l || r < qi) return tree[i];
        if (l == r) {
            arr[qi] = val;
            return tree[i] = op(qi);
        }
        int m = (l + r) / 2;
        return tree[i] = op(update(2 * i + 1, l, m, qi, val), update(2 * i + 2, m + 1, r, qi, val));
    }
};