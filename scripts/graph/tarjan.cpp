#include <bits/stdc++.h>
using namespace std;

void scc(int i, vector<vector<int>>& graph,
        vector<int>& stack, vector<int>& disc,
        vector<int>& low, vector<bool>& inStack, int& t) {

    if (disc[i] != -1) return;

    disc[i] = low[i] = t++;
    inStack[i] = true;
    stack.push_back(i);

    for (int& j : graph[i]) {
        if (disc[j] == -1) {
            scc(j, graph, stack, disc, low, inStack, t);
            low[i] = min(low[i], low[j]);
        } else if (inStack[j]) {
            low[i] = min(low[i], disc[j]);
        }
    }

    if (disc[i] == low[i]) {
        while (stack.back() != i) {
            inStack[stack.back()] = false;
            stack.pop_back();
        }
        inStack[i] = false;
        stack.pop_back();
    }
}