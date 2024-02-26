#include "bits/stdc++.h"
using namespace std;

struct Trie {
    struct Node {
        Node* next[26] = {nullptr};
        int count = 0;
        bool is_end = false;
    };

    Node* root;

    Trie() : root(new Node()) {}

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Node();
            node = node->next[c - 'a'];
            node->count++;
        }
        node->is_end = true;
    }

    bool search(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (node->next[c - 'a'] == nullptr)
                return false;
            node = node->next[c - 'a'];
        }
        return node->is_end;
    }
};