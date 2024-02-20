#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>>& graph) {
    vector<vector<int>> dist(graph);
    for (int k = 0; k < graph.size(); k++)
        for (int i = 0; i < graph.size(); i++)
            for (int j = 0; j < graph.size(); j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return dist;
}