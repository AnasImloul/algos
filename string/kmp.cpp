#include "bits/stdc++.h"
using namespace std;

vector<int> kmp(const string& s, const string& t) {
    vector<int> pi(t.size());
    for (int i = 1, j = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }

    vector<int> matches;
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != t[j])
            j = pi[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == t.size()) {
            matches.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return matches;
}