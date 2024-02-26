#include "bits/stdc++.h"
using namespace std;


vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b, int mod = 1e9 + 7) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++) {
                int add = (int)(((long long) a[i][k] * b[k][j]) % (long long) mod);
                c[i][j] = (c[i][j] + add) % mod;
            }
    return c;
}


vector<vector<int>> power(vector<vector<int>>& a, int n, int mod = 1e9 + 7) {
    vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++)
        res[i][i] = 1;

    while (n > 0) {
        if (n & 1)
            res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        n >>= 1;
    }

    return res;
}