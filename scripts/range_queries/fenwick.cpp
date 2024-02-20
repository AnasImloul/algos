#include "bits/stdc++.h"
using namespace std;

struct Fenwick {
    vector<int> tree;

    Fenwick(int n) : tree(n + 1) {}

    void update(int i, int delta) {
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};