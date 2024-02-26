#include "bits/stdc++.h"
#include "matrix_multiplication.cpp"
using namespace std;

vector<vector<int>> markov_chain(int n, vector<vector<double>>& graph) {
    // graph[i][j] = probability of going from i to j
    return power(graph, n);
}