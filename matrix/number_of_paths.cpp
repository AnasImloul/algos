#include "bits/stdc++.h"
#include "matrix_multiplication.cpp"
using namespace std;


vector<vector<int>> number_of_paths(vector<vector<int>>& adj_matrix, int length) {
    return power(adj_matrix, length);
}

// we can modify the multiplication function to return the minimum length path between two nodes
vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 1e9));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++)
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
    return c;
}