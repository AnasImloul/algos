#include "bits/stdc++.h"
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    int build(int i, int l, int r, vector<int>& arr) {
        if (l == r) return tree[i] = arr[l];
        int m = (l + r) / 2;
        return tree[i] = build(2 * i + 1, l, m, arr) + build(2 * i + 2, m + 1, r, arr);
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[i];
        int m = (l + r) / 2;
        return query(2 * i + 1, l, m, ql, qr) + query(2 * i + 2, m + 1, r, ql, qr);
    }

    int update(int i, int l, int r, int qi, int val) {
        if (qi < l || r < qi) return tree[i];
        if (l == r) return tree[i] = val;
        int m = (l + r) / 2;
        return tree[i] = update(2 * i + 1, l, m, qi, val) + update(2 * i + 1, m + 1, r, qi, val);
    }
};