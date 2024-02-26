#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>,null_type,std::less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int main() {
    int t = 0;

    indexed_set me;

    int x = 2;

    me.insert({x, t++});
    me.erase(me.lower_bound({x, 0}));
    cout << me.order_of_key({x, 0}) << "\n";
}