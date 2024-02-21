#include <bits/stdc++.h>
using namespace std;


class SegmentTree {
private:
    vector<int> tree, arr, lazy;

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if(lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(start > end || start > r || end < l) return;
        if(start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if(start != end) {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(2*node, start, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int start, int end, int l, int r) {
        if(start > end || start > r || end < l) return 0;
        if(lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if(start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return (p1 + p2);
    }

public:
    explicit SegmentTree(vector<int>& nums) {
        arr = nums;
        tree.resize(4 * arr.size());
        lazy.resize(4 * arr.size());
        build(1, 0, (int)arr.size() - 1);
    }

    void update(int l, int r, int val) {
        update(1, 0, (int)arr.size() - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(1, 0, (int)arr.size() - 1, l, r);
    }
};

