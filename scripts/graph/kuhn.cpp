# include <bits/stdc++.h>
using namespace std;

vector<int> kuhn(vector<vector<int>>& graph) {
    vector<int> inOrder(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
        for (int& j : graph[i])
            inOrder[j]++;

    queue<int> q;
    for (int i = 0; i < graph.size(); i++)
        if (inOrder[i] == 0)
            q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        order.push_back(i);
        for (int& j : graph[i]) {
            inOrder[j]--;
            if (inOrder[j] == 0)
                q.push(j);
        }
    }
    return (order.size() == graph.size()) ? order : vector<int>();
}