bool isPossible(int n) {
    return n >= 1000;
}

int binarySearch(int l, int r) {
    int res = -1, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (isPossible(mid)) {
            res = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return res;
}