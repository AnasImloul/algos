#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

// Usage:
// indexed_set s;
// s.insert(2);
// s.insert(3)
// s.find_by_order(0); // 2
// s.order_of_key(2); // 0