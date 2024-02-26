int pow(int a, int b, int n) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}